#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
#include <locale.h>
#include "queue.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Queue<int> queue(5);

	queue.Push(10);
	cout << "очередь: " << queue << endl;
	queue.Push(20);
	queue.Push(30);
	queue.Push(40);
	queue.Push(50);

	cout << "первый элемент очереди: " << queue.Front() << endl;
	cout << "последний элемент очереди: " << queue.Back() << endl;

	cout << "очередь: " << queue << endl;

	queue.Pop();
	cout << "очередь: " << queue << endl;

	queue.Push(100);
	cout << "очередь: " << queue << endl;


}