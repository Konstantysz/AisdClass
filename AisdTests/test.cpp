#include "gtest/gtest.h"

#include "DataStructures.h"
#include "DataStructuresUtils.h"

#define MAX_ARR 1000

TEST(HeapTest, HeapConstructorTest1) {
	int values = 1;
	auto heap = aisd::Heap<int>(&values, MAX_ARR);

	ASSERT_TRUE(heap.IsHeapCorrect());
}

TEST(HeapTest, HeapConstructorTest2) {
	int values[MAX_ARR] = {
		7, 58, 76, 96, 67, 13, 14, 38, 66, 32,
		39, 45, 57, 17, 6, 35, 72, 23, 74, 8,
		70, 2, 75, 20, 21, 79, 56, 15, 42, 31,
		59, 83, 84, 48, 36, 33, 73, 10, 24, 62,
		37, 98, 89, 97, 99, 95, 53, 81, 44, 47,
		11, 63, 5, 30, 65, 16, 4, 27, 3, 49, 19,
		87, 61, 64, 51, 43, 40, 41, 18, 55, 80,
		9, 93, 26, 69, 12, 29, 60, 52, 86, 100,
		54, 88, 50, 28, 85, 78, 1, 91, 92,
		77, 22, 25, 71, 94, 34, 68, 46, 82, 90
	};
	auto heap = aisd::Heap<int>(values, MAX_ARR);

	ASSERT_TRUE(heap.IsHeapCorrect());
}

TEST(BeapTest, BeapConstructorTest1) {
	int values[MAX_ARR] = { 
		7, 58, 76, 96, 67, 13, 14, 38, 66, 32, 
		39, 45, 57, 17, 6, 35, 72, 23, 74, 8, 
		70, 2, 75, 20, 21, 79, 56, 15, 42, 31, 
		59, 83, 84, 48, 36, 33, 73, 10, 24, 62, 
		37, 98, 89, 97, 99, 95, 53, 81, 44, 47, 
		11, 63, 5, 30, 65, 16, 4, 27, 3, 49, 19, 
		87, 61, 64, 51, 43, 40, 41, 18, 55, 80, 
		9, 93, 26, 69, 12, 29, 60, 52, 86, 100, 
		54, 88, 50, 28, 85, 78, 1, 91, 92, 
		77, 22, 25, 71, 94, 34, 68, 46, 82, 90 
	};
	auto beap = aisd::Beap<int>(values, MAX_ARR);

	ASSERT_TRUE(beap.IsBeapCorrect());
}