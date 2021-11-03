#pragma once
#include <iostream>
#include "DataStructuresUtils.h"

namespace aisd
{
	template <class T>
	class Heap
	{
		T* A;
		int hl;
		int maxSize;

	public:
		Heap(int arrSize)
		{
			if(arrSize > 1) 
			{
				maxSize = arrSize;
				A = new T[size_t(arrSize + 1)];
				hl = 0;
			}
		}

		~Heap()
		{
			delete[] A;
		}

		void Insert(T v)
		{
			if (hl == maxSize) return;

			A[hl + 1] = v;
			hl++;
		}

		void PrintAll()
		{
			if (hl == 0) return;

			int lastInRowId = 1;

			for (int i = 1; i <= hl; i++)
			{
				std::cout << A[i];
				if (i == lastInRowId)
				{
					std::cout << std::endl;
					lastInRowId = 2 * i + 1;
				}
				else if (i != hl)
				{
					std::cout << " | ";
				}
			}

			std::cout << std::endl;
		}
	
		void DownHeap(int i)
		{
			while (1)
			{
				if (2 * i > hl) return; // node doesn't have next elements

				int k = 2 * i;

				if (2 * i + 1 <= hl && A[2 * i + 1] > A[2 * i]) // right node has higher value than left
				{
					k = 2 * i + 1;
				}

				if (A[k] < A[i]) return; // both lower nodes have lower value

				aisd::utils::SwapValues<T>(A[i], A[k]);

				i = k;
			}
		}

		void SortHeap()
		{
			for (int i = hl / 2; i > 0; i--)
			{
				DownHeap(i);
			}

			if (ProperHeap())
			{
				std::cout << "Heap is correct!" << std::endl;
				return;
			}

			std::cout << "Incorrect heap!" << std::endl;
		}

		bool ProperHeap()
		{
			for (int i = 1; i <= hl; i++)
			{
				if (2 * i <= hl && A[2 * i] > A[i]) return false;
				if (2 * i + 1 <= hl && A[2 * i + 1] > A[i]) return false;
			}

			return true;
		}

		void UpHeap(int i)
		{
			while (1)
			{
				if (i / 2 == 0) return; // node doesn't have next elements
				
				int k = i / 2;

				if (A[k] > A[i]) return; // upper node has higher value

				aisd::utils::SwapValues<T>(A[i], A[k]);

				i = k;
			}
			return;
		}

		void BuildHeapFromFromTop(T values[])
		{
			int i = 0;
			while (values[i])
			{
				Insert(values[i]);
				UpHeap(i + 1);
				i++;
			}
		}

		void BuildHeapFromFromBottom(T values[])
		{
			int i = 0;
			while (values[i])
			{
				Insert(values[i]);
				i++;
			}
			SortHeap();
		}
	};
} // namespace aisd
