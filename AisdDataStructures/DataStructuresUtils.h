#pragma once

namespace aisd 
{	
	namespace utils
	{
		template <class T>
		void SwapValues(T& a, T& b)
		{
			T temp = a;
			a = b;
			b = temp;
		}
	} // namespace utils
} // namespace aisd