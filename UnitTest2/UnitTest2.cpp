#include "CppUnitTest.h"
#include "../astra_l2/astr_l2.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		int* Array;
		// before each test
		TEST_METHOD_INITIALIZE(setUp)
		{
			Array = creating_Array_int(10);
		}
		// after each test
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete[] Array;
		}
		TEST_METHOD(is_sorted_not_sorted_array)
		{
			for (int i = 0; i < 10; i++) {
				Array[i] = 1;
			}
			Array[5] = 60;
			Assert::IsFalse(is_sorted(Array, 10));
		}
		TEST_METHOD(is_sorted_sorted_array)
		{
			for (int i = 0; i < 10; i++) {
				Array[i] = i;
			}
			Assert::IsTrue(is_sorted(Array,10));
		}
		TEST_METHOD(is_sorted_equal_elements)
		{
			for (int i = 0; i < 10; i++) {
				Array[i] = 1;
			}
			Assert::IsTrue(is_sorted(Array, 10));
		}
		TEST_METHOD(is_sorted_not_sorted_array_char)
		{
			char* Array_char = new char [10];
			for (int i = 0; i < 10; i++) {
				Array_char[i] = i;
			}
			Array_char[5] = 60;
			Assert::IsFalse(is_sorted(Array_char, 10));
		}
		TEST_METHOD(is_sorted_sorted_array_char)
		{
			char* Array_char = new char[10];
			for (int i = 0; i < 10; i++) {
				Array_char[i] = i;
			}
			Assert::IsTrue(is_sorted(Array_char, 10));
		}
		TEST_METHOD(is_sorted_equal_elements_char)
		{
			char* Array_char = new char[10];
			for (int i = 0; i < 10; i++) {
				Array_char[i] = 1;
			}
			Assert::IsTrue(is_sorted(Array_char, 10));
		}
		TEST_METHOD(BinarySearch_Array_is_not_sorted)
		{
			for (int i = 0; i < 10; i++) {
				Array[i] = i;
			}
			Array[5] = 60;
			try {
				BinarySearch(Array, 10, 5);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Array is not sorted", e.what());
			}
		}
		TEST_METHOD(BinarySearch_key_exist)
		{
			for (int i = 0; i < 10; i++) {
				Array[i] = i;
			}
			Assert::AreEqual(BinarySearch(Array,10,5),5);
		}
		TEST_METHOD(BinarySearch_key_dosent_exist)
		{
			for (int i = 0; i < 10; i++) {
				Array[i] = i;
			}
			try {
				BinarySearch(Array, 10, 20);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("The key doesn't exist", e.what());
			}
		}
		TEST_METHOD(QuickSort_test)
		{
			for (int i = 9; i >= 0; i--) {
				Array[i] = i;
			}
			QuickSort(Array, 10);
			Assert::IsTrue(is_sorted(Array, 10));
		}
		TEST_METHOD(QuickSort_equal_elements)
		{
			for (int i = 9; i >= 0; i--) {
				Array[i] = i;
			}
			Array[8] = 7;
			QuickSort(Array, 10);
			Assert::IsTrue(is_sorted(Array, 10));
		}
		TEST_METHOD(InsertionSort_test)
		{
			for (int i = 9; i >= 0; i--) {
				Array[i] = i;
			}
			InsertionSort(Array, 10);
			Assert::IsTrue(is_sorted(Array, 10));
		}
		TEST_METHOD(InsertionSortt_equal_elements)
		{
			for (int i = 9; i >= 0; i--) {
				Array[i] = i;
			}
			Array[8] = 7;
			InsertionSort(Array, 10);
			Assert::IsTrue(is_sorted(Array, 10));
		}
		TEST_METHOD(BogoSort_test)
		{
			for (int i = 9; i >= 0; i--) {
				Array[i] = i;
			}
			BogoSort(Array, 10);
			Assert::IsTrue(is_sorted(Array, 10));
		}
		TEST_METHOD(BogoSort_equal_elements)
		{
			for (int i = 9; i >= 0; i--) {
				Array[i] = i;
			}
			Array[8] = 7;
			BogoSort(Array, 10);
			Assert::IsTrue(is_sorted(Array, 10));
		}
		TEST_METHOD(CountingSort_test)
		{
			char* Array_char = new char[10];
			for (int i = 9; i >= 0; i--) {
				Array_char[i] = i;
			}
			CountingSort(Array_char, 10);
			Assert::IsTrue(is_sorted(Array_char, 10));
		}
		TEST_METHOD(CountingSort_equal_elements)
		{
			char* Array_char = new char[10];
			for (int i = 9; i >= 0; i--) {
				Array_char[i] = i;
			}
			Array[8] = 3;
			CountingSort(Array_char, 10);
			Assert::IsTrue(is_sorted(Array_char, 10));
		}
	};
}
