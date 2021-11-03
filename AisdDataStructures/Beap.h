#pragma once
#include <iostream>
#include <stdexcept>
#include <utility>

#include "DataStructuresUtils.h"

/*! \file Beap.h
	Declares class used to implement Beap data structure.
*/

namespace aisd
{
	/*! \class Beap
		Class template implementing Beap data structure.
		\tparam T Type to work with.
	*/
	template <class T>
	class Beap
	{
		T* A; //!< Array in which Beap is implemented.
		int hl; //!< Last element index.
		int maxSize; //!< Maximal number of values that can be stored in Beap array.

	public:
		/*! Beap constructor with no stored values.
			\param[in] arrSize Maximal number of stored values in the Beap.
		*/
		Beap(int arrSize)
		{
			if (arrSize > 1)
			{
				maxSize = arrSize - 1;
				A = new T[arrSize];
				hl = 0;
			}
			else
			{
				throw std::invalid_argument("Beap array size must be greater than 1!");
			}
		}

		/*! Beap constructor with values from array.
			\param[in] values Array of values to be stored in the beap.
			\param[in] arrSize Maximal number of stored values in the beap.
		*/
		Beap(T values[], int arrSize)
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
				throw std::invalid_argument("Beap array size must be greater than 1!");
			}
		}
		
		/*! Method to add values to beap from top.
			\param[in] values Array of values to be stored in the beap.
		*/
		void StoreValuesFromTop(T values[])
		{
			int i = 0;
			while (values[i])
			{
				Insert(values[i]);
				UpBeap(i + 1);
				i++;
			}
		}

		/*! Method to add values to beap from bottom.
			Prefered way to add elements to beap, as it has better time complexity.
			\param[in] values Array of values to be stored in the beap.
		*/
		void StoreValuesFromBottom(T values[])
		{
			int i = 0;
			while (values[i])
			{
				Insert(values[i]);
				i++;
			}
			for (int i = hl /*/ 2*/; i > 0; i--)
			{
				DownBeap(i);
			}
		}

		// TODO: Write DelMax
		/*! Method to delete element with maximal value.
			\returns Beap element with maximal value.
		*/
		T DelMax()
		{
			return A[1];
		}

		// TODO: Write Search
		/*! Method to search value index in beap.
			\param[in] value Searched value.
			\returns Index of the value in the beap.
		*/
		int Search(T v)
		{
			return -1;
		}

		// TODO: wrute PrintAll
		//! Method to print all beap elements
		void PrintAll()
		{
			for (int k = 1; k <= hl; k++)
			{
				int i = k2ij(k).first;
				int j = k2ij(k).second;

				std::cout << A[k];
				if (i != j) std::cout << " | ";
				else std::cout << std::endl;
			}
		}

		/*! Method to check if beap follows beap rules.
			\returns Beap correctness.
		*/
		bool IsBeapCorrect()
		{
			for (int k = 1; k <= hl; k++)
			{
				int i = k2ij(k).first;
				int j = k2ij(k).second;

				if (ij2k(i - 1, j - 1) > 0 && A[k] > A[ij2k(i - 1, j - 1)]) 
					return false;
				if (ij2k(i - 1, j) > 0 && A[k] > A[ij2k(i - 1, j)]) 
					return false;

				if (ij2k(i + 1, j) <= hl && A[k] < A[ij2k(i + 1, j)]) 
					return false;
				if (ij2k(i + 1, j + 1) <= hl && A[k] < A[ij2k(i + 1, j + 1)]) 
					return false;
			}

			return true;
		}

	private:
		/*! Method to get (i,j) coordinates of the element based on index.
			\param[in] k Index of the element.
			\returns Pair of (i, j) coordinates.
		*/
		std::pair<int, int> k2ij(int k)
		{
			int i = int(ceil(0.5 * (-1 + sqrt(1.0 + 8 * k))));
			int j = int(k - 0.5 * i * (i - 1));;
			return std::make_pair(i, j);
		}

		/*! Method to get index of the element based on (i,j) coordinates.
			\param[in] i Row of the element.
			\param[in] j Column of the element.
			\returns Index value of the element.
		*/
		int ij2k(int i, int j)
		{
			return (i == 0 || j == 0 || i < j) ? 0 :(i - 1) * i / 2 + j;
		}

		/*! Method to store value in the beap at the end.
			\param[in] v Value to store.
		*/
		void Insert(T v)
		{
			if (hl == maxSize) return;

			A[hl + 1] = v;
			hl++;
		}

		/*! Method to push down element at specific index to position that will follow beap rules.
			\param[in] v Starting index.
		*/
		void DownBeap(int k)
		{
			int x = A[k];
			int i = k2ij(k).first;
			int k1 = k;
			k = k + i;
			i++;
			while (k <= hl)
			{
				if (k < hl && A[k + 1] > A[k])
				{
					k++;
				}
				if (A[k] > x)
				{
					A[k1] = A[k];
					k1 = k;
					k = k + i;
					i++;
				}
				else
				{
					break;
				}
			}
			A[k1] = x;
		}

		/*! Method to pull up element at specific index to position that will follow beap rules.
			\param[in] v Starting index.
		*/
		void UpBeap(int k)
		{
			int x = A[k];
			int i = k2ij(k).first;
			int j = k2ij(k).second;
			int k1 = k;

			while (i > 1)
			{
				if (j == 1)
				{
					k = k - i + 1;
				}
				else if (j == i)
				{
					k = k - i;
					j--;
				}
				else
				{
					k = k - i;
					j--;
					if (A[k + 1] < A[k])
					{
						k++;
						j++;
					}
				}

				if (A[k] < x)
				{
					A[k1] = A[k];
					k1 = k;
					i--;
				}
				else
				{
					break;
				}
				A[k1] = x;
			}
		}
	};
} // namespace aisd
