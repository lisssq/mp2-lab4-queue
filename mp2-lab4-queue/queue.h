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

	friend istream& operator>>(istream& in, Queue& q)
	{
		T val;
		cout << "Введите элементы стека (введите 0 для завершения): ";
		while (in >> val && val != 0)
		{
			if (!q.isFull())
			{
				q.Push(val);
			}
			else
			{
				throw - 2;
				break;
			}
		}
		return in;
	}


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

	

	Queue(int _size = 10)
	{
		pMem = new T[_size];
		size = _size;
		count = 0;
		head = 0;
		tail = -1;
	}

	// реализовать деструктор, конструктор копирования, оператор сравнения (== и !=)


	~Queue()
	{
		delete[] pMem;
	}


	Queue (const Queue& q)//конструктор копирования
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

	bool operator==(const Queue& q)
	{
		if (size != q.size || count != q.count)
		{
			return false;
		}
		for (int i = 0; i < size; i++)
		{
			if (pMem[i] != q.pMem[i])
			{
				return false;
			}
		}
		return true;
	}


	bool operator!=(const Queue& q)
	{
		return!(*this == q);
	}


	bool isEmpty() const
	{
		return count == 0;
	}

	bool isFull() const
	{
		return count == size;
	}

	void Push(T val)
	{
		if (this->isFull())
		{
			throw - 1; //проверка на полноту
		}
		if (tail == size - 1)
		{
			tail = 0;
		}
		else
		{
			tail++;
		}
		//tail = (tail + 1) % size; // Циклическое изменение tail
		pMem[tail] = val;
		count++;


	}

	T Pop()
	{
		int ind = head;
		if (head == size - 1)
		{
			head = 0;
		}
		else
		{
			head++;
		}
		count--;
		return pMem[ind];
	}

	T Front() const
	{
		if (isEmpty())
		{
			throw - 1;
		}
		return pMem[head];
	}



	T Back() const
	{
		if (isEmpty())
		{
			throw - 1;
		}
		return pMem[tail];
	}
	// написать методы Front и Back которые смотрят кто первый кто последний (похож на метод Top)

};
