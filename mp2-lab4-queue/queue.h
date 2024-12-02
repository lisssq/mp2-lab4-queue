
#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <cmath>

using namespace std;

template <class T>
class Queue
{
	T* pMem;	// массив для хранения элементов
	int size;	// максимальный размер очереди
	int head;	// указатель на начало очереди
	int tail;	// указатель на конец очереди
	int count;	// текущее кол-во элементов в очереди


	//friend istream& operator>>(istream& in, Queue& q)
	//{
	//	T val;
	//	cout << "Введите элементы (введите 0 для завершения): ";
	//	while (in >> val && val != 0)
	//	{
	//		if (!q.isFull())
	//		{
	//			q.Push(val);
	//		}
	//		else
	//		{
	//			throw - 2;
	//			break;
	//		}
	//	}
	//	return in;
	//}


	friend ostream& operator<<(ostream& out, const Queue& q)
	{
		if (q.isEmpty())
		{
			out << "" << endl;
			return out;
		}
		int index = q.head;
		for (int i = 0; i < q.count; i++)
		{
			out << q.pMem[index] << " ";
			index = (index + 1) % q.size;	// переход по кругу
		}
		return out;
	}

public:

	Queue();
	Queue(int _size = 10);
	~Queue();
	Queue(const Queue& q);

	Queue<T>& operator=(const Queue<T>& q);
	bool operator==(const Queue& q);
	bool operator!=(const Queue& q);

	bool isEmpty() const;
	bool isFull() const;
	void Push(T val);
	T Pop();
	T Front() const;
	T Back() const;

	int GetHeadIndex();//Получить индекс, на котором стоит первый элемент в очереди
	int MaxSize(); //Получить размер хранилища
	int CountElements();   //Количество элементов в очереди
	int GetSizeNow(); //Получить текущий размер

};



template <class T>
Queue<T>::Queue()
{
	size = 10;
}




template <class T>
Queue<T>::Queue(int _size)
{
	pMem = new T[_size];
	size = _size;
	count = 0;
	head = 0;
	tail = -1;
}

// реализовать деструктор, конструктор копирования, оператор сравнения (== и !=)


template <class T>
Queue<T>::~Queue()
{
	delete[] pMem;
}


template <class T>
Queue<T>::Queue(const Queue<T>& q)     //конструктор копирования
{
	size = q.size;
	count = q.count;
	head = q.head;
	tail = q.tail;
	pMem = new T[size];
	for (int i = 0; i < size; i++)
	{
		pMem[i] = q.pMem[i];
	}
}


template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q)
{
	if (this == &q)
	{
		// Самоприсваивание: ничего делать не нужно.
		return *this;
	}
	delete[] pMem;
	size = q.size;
	head = q.head;
	tail = q.tail;
	count = q.count;

	pMem = new T[size];
	for (int i = 0; i < size; i++)
	{
		pMem[i] = q.pMem[i];
	}

	return *this;
}



template <class T>
bool Queue<T>::operator==(const Queue<T>& q)	// (???) сравнивать очереди необходимо по значениям,
// а не по местам расположения этих элементов
{
	if (size != q.size || count != q.count)
	{
		return false;
	}
	else
	{
		Queue this_q = *this;	 // Временная копия текущей очереди.
		Queue q_q = q;			 // Временная копия другой очереди.
		while (!this_q.isEmpty())
		{
			if (this_q.Front() != q_q.Front())		// Если хотя бы один элемент отличается, очереди не равны.
			{
				return false;
			}
			this_q.Pop();		// Удаление элементов из временных очередей.
			q_q.Pop();
		}

	}


	return true;		// Очереди равны.
}


template <class T>
bool Queue<T>::operator!=(const Queue<T>& q)
{
	return!(*this == q);
}


template <class T>
bool Queue<T>::isEmpty() const
{
	return count == 0;
}

template <class T>
bool Queue<T>::isFull() const
{
	return count == size;
}

template <class T>
void Queue<T>::Push(T val)
{
	if (this->isFull())
	{
		throw "очередь переполнена"; //проверка на полноту
	}
	/*if (tail == size - 1)
	{
		tail = 0;
	}
	else
	{
		tail++;
	}*/
	tail = (tail + 1) % size; // Зацикливание индекса.
	pMem[tail] = val;	// Добавление элемента в очередь.
	count++;			// Увеличение количества элементов.


}

template <class T>
T Queue<T>::Pop()
{
	if (this->isEmpty())
	{
		throw "очередь пуста";
	}
	int ind = head;
	/*
	if (head == size - 1)
	{
		head = 0;
	}
	else
	{
		head++;
	}
	count--;
	return pMem[ind];*/

	// Обновляем указатель head по кругу
	head = (head + 1) % size;
	count--;
	return pMem[ind];

}

template <class T>
T Queue<T>::Front() const
{
	if (isEmpty())
	{
		throw "очередь пуста";
	}
	return pMem[head];
}



template <class T>
T Queue<T>::Back() const
{
	if (isEmpty())
	{
		throw "очередь пуста";
	}
	return pMem[tail];
}

template<class T>
int Queue<T>::GetHeadIndex()
{
	return head;
}

template<class T>
int Queue<T>::MaxSize()
{
	return size;
}

template<class T>
int Queue<T>::CountElements()
{
	return count;
}

template<class T>
int Queue<T>::GetSizeNow()
{
	return count;
}
