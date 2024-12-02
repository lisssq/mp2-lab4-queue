
#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <cmath>

//using namespace std;

template <class T>
class TQueue
{
	T* pMem;	// массив для хранения элементов
	int size;	// максимальный размер очереди
	int head;	// указатель на начало очереди
	int tail;	// указатель на конец очереди
	int count;	// текущее кол-во элементов в очереди


	//friend istream& operator>>(istream& in, TQueue& q)
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


	friend std::ostream& operator<<(std::ostream& out, const TQueue& q)
	{
		if (q.isEmpty())
		{
			out << "" << std::endl;
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

	TQueue();
	TQueue(int _size = 10);
	~TQueue();
	TQueue(const TQueue& q);

	TQueue<T>& operator=(const TQueue<T>& q);
	bool operator==(const TQueue& q);
	bool operator!=(const TQueue& q);

	bool isEmpty() const;
	bool isFull() const;
	void Push(T val);
	T Pop();
	T Front() const;
	T Back() const;

	int GetHeadIndex();//Получить индекс, на котором стоит первый элемент в очереди
	int GetMaxSize(); //Получить размер хранилища
	int CountElements();   //Количество элементов в очереди
	int GetSizeNow(); //Получить текущий размер

};



template <class T>
TQueue<T>::TQueue()
{
	size = 10;
}



template <class T>
TQueue<T>::TQueue(int _size)
{
	pMem = new T[_size];
	size = _size;
	count = 0;
	head = 0;
	tail = -1;
}

// реализовать деструктор, конструктор копирования, оператор сравнения (== и !=)


template <class T>
TQueue<T>::~TQueue()
{
	delete[] pMem;
}


template <class T>
TQueue<T>::TQueue(const TQueue<T>& q)     //конструктор копирования
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
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& q)
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
bool TQueue<T>::operator==(const TQueue<T>& q)	
{
	if (size != q.size || count != q.count)
	{
		return false;
	}
	else
	{
		TQueue this_q = *this;	 // Временная копия текущей очереди.
		TQueue q_q = q;			 // Временная копия другой очереди.
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
bool TQueue<T>::operator!=(const TQueue<T>& q)
{
	return!(*this == q);
}


template <class T>
bool TQueue<T>::isEmpty() const
{
	return count == 0;
}

template <class T>
bool TQueue<T>::isFull() const
{
	return count == size;
}

template <class T>
void TQueue<T>::Push(T val)
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
T TQueue<T>::Pop()
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
T TQueue<T>::Front() const
{
	if (isEmpty())
	{
		throw "очередь пуста";
	}
	return pMem[head];
}



template <class T>
T TQueue<T>::Back() const
{
	if (isEmpty())
	{
		throw "очередь пуста";
	}
	return pMem[tail];
}

template<class T>
int TQueue<T>::GetHeadIndex()
{
	return head;
}

template<class T>
int TQueue<T>::GetMaxSize()
{
	return size;
}

template<class T>
int TQueue<T>::CountElements()
{
	return count;
}

template<class T>
int TQueue<T>::GetSizeNow()
{
	return count;
}
