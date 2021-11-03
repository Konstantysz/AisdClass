#pragma once
#include <iostream>
#include <stdexcept>


#include "DataStructuresUtils.h"

/*! \file Heap.h
	Declares class used to implement heap data structure.
*/

namespace aisd
{
	/*! \class Heap
		Class template implementing heap data structure.
		\tparam T Type to work with.
	*/
	template <class T>
	class Heap
	{
		T* A; //!< Array in which heap is implemented.
		int hl; //!< Last element index.
		int maxSize; //!< Maximal number of values that can be stored in heap array.

	public:
		/*! Heap constructor with no stored values.
			\param[in] arrSize Maximal number of stored values in the heap.
		*/
		Heap(int arrSize)
		{
			if(arrSize > 1) 
			{
				maxSize = arrSize - 1;
				A = new T[arrSize];
				hl = 0;
			}
			else
			{
				throw std::invalid_argument("Heap array size must be greater than 1!");
			}
		}

		/*! Heap constructor with values from array.
			\param[in] values Array of values to be stored in the heap.
			\param[in] arrSize Maximal number of stored values in the heap.
		*/
		Heap(T values[], int arrSize)
		{
			arrSize++;
			if (arrSize > 1)
			{
				maxSize = arrSize - 1;
				A = new T[arrSize];
				hl = 0;

				StoreValuesFromBottom(values);
			}
			else 
			{
				throw std::invalid_argument("Heap array size must be greater than 1!");
			}
		}

		//! Heap destructor
		~Heap()
		{
			delete[] A;
		}

		/*! Method to add values to heap from top.
			\param[in] values Array of values to be stored in the heap.
		*/
		void StoreValuesFromTop(T values[])
		{
			int i = 0;
			while (values[i])
			{
				Insert(values[i]);
				UpHeap(i + 1);
				i++;
			}
		}

		/*! Method to add values to heap from bottom.
			Prefered way to add elements to heap, as it has better time complexity.
			\param[in] values Array of values to be stored in the heap.
		*/
		void StoreValuesFromBottom(T values[])
		{
			int i = 0;
			while (values[i])
			{
				Insert(values[i]);
				i++;
			}
			for (int i = hl / 2; i > 0; i--)
			{
				DownHeap(i);
			}
		}

		// TODO: Write DelMax
		/*! Method to delete element with maximal value.
			\returns Heap element with maximal value.
		*/
		T DelMax()
		{
			return A[1];
		}

		// TODO: Write Search
		/*! Method to search value index in heap.
			\param[in] value Searched value.
			\returns Index of the value in the heap.
		*/
		int Search(T v)
		{
			return -1;
		}

		//! Method to print all heap elements
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

		/*! Method to check if heap follows heap rules.
			\returns Heap correctness.
		*/
		bool IsHeapCorrect()
		{
			for (int i = 1; i <= hl; i++)
			{
				if (2 * i <= hl && A[2 * i] > A[i]) return false;
				if (2 * i + 1 <= hl && A[2 * i + 1] > A[i]) return false;
			}

			return true;
		}

	private:
		/*! Method to store value in the heap at the end.
			\param[in] v Value to store.
		*/
		void Insert(T v)
		{
			if (hl == maxSize) return;

			A[hl + 1] = v;
			hl++;
		}
	
		/*! Method to push down element at specific index to position that will follow heap rules.
			\param[in] v Starting index.
		*/
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

		/*! Method to pull up element at specific index to position that will follow heap rules.
			\param[in] v Starting index.
		*/
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
	};
} // namespace aisd
