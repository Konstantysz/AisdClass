#pragma once
#include <iostream>

namespace aisd 
{
	template <typename T>
	struct Node
	{
		T val;
		Node<T>* next;

		Node(T v, Node<T>* n = nullptr)
		{
			val = v;
			next = n;
		}
	};

	template <typename T>
	class LinkedList
	{
		Node<T>* head;

	public:
		void Insert(T v)
		{
			Node<T>* newHead = new Node<T>(v);
			newHead->next = head;
			head = newHead;
		}

		void PrintAll()
		{
			Node<T>* p = head;
			while (p)
			{
				std::cout << p->val << std::endl;
				p = p->next;
			}
		}
	};
} // namespace aisd

