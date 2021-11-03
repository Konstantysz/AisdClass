#pragma once
#include <iostream>

namespace aisd 
{
	template <class T>
	class Tree
	{
		template <typename T>
		struct Node
		{
			T val;
			Node<T>* right;
			Node<T>* left;

			Node(T v, Node<T>* l = nullptr, Node<T>* r = nullptr)
			{
				val = v;
				right = r;
				left = l;
			}
		};

		Node<T>* root;

	public:

		void Insert(T v)
		{
			return;
		}
	};
} // namespace aisd
