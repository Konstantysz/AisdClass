#pragma once

namespace aisd
{
	template <class T>
	class Stack
	{
	private:
		T* sArr;
		int i;

	public:
		Stack(int nMax)
		{
			sArr = new T[nMax];
			i = 0;
		}

		~Stack()
		{
			delete[] sArr;
		}

		bool IsEmpty()
		{
			return i == 0;
		}

		void Push(T v)
		{
			sArr[i++] = v;
		}

		T Pop()
		{
			return sArr[--i];
		}
	};
} //namespace aisd
