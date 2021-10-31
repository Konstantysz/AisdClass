#include <iostream>
#include "DataStructures.h"

int main()
{
	auto list = aisd::LinkedListWithTail<int>();

	list.Insert(4);
	list.Insert(3);
	list.Insert(1);
	list.InsertLast(2);
	list.PrintAll();

	auto queue = aisd::Queue<int>(10);
	std::cout << queue.IsEmpty() << std::endl;
	std::cout << queue.IsFull() << std::endl;

	return 0;
}
