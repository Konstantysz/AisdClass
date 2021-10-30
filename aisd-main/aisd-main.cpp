#include <iostream>
#include "LinkedList.h"

int main()
{
	auto list = aisd::LinkedList<int>();

	list.Insert(4);
	list.PrintAll();

	list.Insert(3);
	list.Insert(1);
	list.Insert(2);
	list.PrintAll();

	return 0;
}
