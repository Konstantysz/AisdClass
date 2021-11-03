#include "gtest/gtest.h"

#include "DataStructures.h"
#include "DataStructuresUtils.h"

#define MAX_ARR 1000

TEST(HeapTest, HeapConstructorTest1) {
	int values = 1;
	auto heap = aisd::Heap<int>(&values, MAX_ARR);

	ASSERT_TRUE(heap.ProperHeap());
}

TEST(HeapTest, HeapConstructorTest2) {
	int values[MAX_ARR] = { 10, 11, 13, 2, 3, 4, 5 };
	auto heap = aisd::Heap<int>(values, MAX_ARR);

	ASSERT_TRUE(heap.ProperHeap());
}
