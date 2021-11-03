#include <iostream>
#include <chrono>

#include "DataStructures.h"

int main()
{
	std::cout << "LINKED LIST" << std::endl;
	auto list = aisd::LinkedListWithTail<int>();
	list.Insert(4);
	list.Insert(3);
	list.Insert(1);
	list.InsertLast(2);
	list.PrintAll();

	std::cout << std::endl;
	std::cout << "QUEUE" << std::endl;
	auto queue = aisd::Queue<int>(10);
	std::cout << queue.IsEmpty() << std::endl;
	std::cout << queue.IsFull() << std::endl;

	std::cout << std::endl;
	std::cout << "HEAP" << std::endl;
	int values[1000] = { 2, 3, 5, 6, 7, 1, 12, 15, 4, 7, 19, 11, 40, 31, 99, 101, 132, 8, 53 };

	auto heap1 = aisd::Heap<int>(1000);
	auto begin1 = std::chrono::steady_clock::now();
	heap1.StoreValuesFromBottom(values);
	auto end1 = std::chrono::steady_clock::now();
	std::cout << "Execution time = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count() << "[ns]" << std::endl;
	heap1.PrintAll();

	auto heap2 = aisd::Heap<int>(1000);
	auto begin2 = std::chrono::steady_clock::now();
	heap2.StoreValuesFromTop(values);
	auto end2 = std::chrono::steady_clock::now();
	std::cout << "Execution time = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2).count() << "[ns]" << std::endl;
	heap2.PrintAll();
}
