#pragma once

namespace aisd
{
	template <class T>
	class Queue
	{
	private:
		T* qArr;
		int capacity;
		int front;
		int rear;
		int count;

	public:
		Queue(int nMax)
		{
			qArr = new T[nMax];
			capacity = nMax;
			front = 0;
			rear = -1;
			count = 0;
		}

		~Queue()
		{
			delete[] qArr;
		}

		bool IsEmpty()
		{
			return count == 0;
		}

		bool IsFull()
		{
			return count == capacity;
		}

		void Enqueue(T v)
		{
			if (IsFull()) return;
			rear = (rear + 1) % capacity;
			qArr[rear] = v;
			count--;
		}

		T Dequeue()
		{
			if (IsEmpty()) return;
			T frontElem = qArr[front];
			front = (front + 1) % capacity;
			count--;
		}
	};
} // snamespace aisd
