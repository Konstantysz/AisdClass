#pragma once
#include <iostream>

namespace aisd 
{
	template <class T>
	class LinkedList
	{
	protected:
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

		Node<T>* head = nullptr;

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
				std::cout << p->val;
				p = p->next;
				if (p)
				{
					std::cout << " -> ";
				}
			}
			std::cout << std::endl;
		}

		void InsertLast(T v)
		{
			Node<T>* p = head;
			while (p->next)
			{
				p = p->next;
			}
			p->next = new Node<T>(v);
		}
	};

	template <class T>
	class LinkedListWithTail : public LinkedList<T>
	{
		typename LinkedList<T>::template Node<T>* tail = nullptr;

	public:
		void Insert(T v)
		{
			typename LinkedList<T>::template Node<T>* newHead = new typename LinkedList<T>::template Node<T>(v);
			newHead->next = LinkedList<T>::head;
			LinkedList<T>::head = newHead;
			if (!tail)
			{
				tail = newHead;
			}
		}

		void InsertLast(T v)
		{
			typename LinkedList<T>::template Node<T>* p = new typename LinkedList<T>::template Node<T>(v);

			if (!LinkedList<T>::head)
			{
				LinkedList<T>::head = p;
				tail = p;
			}
			else
			{
				tail->next = p;
			}
			tail = p;
		}
	};
} // namespace aisd

