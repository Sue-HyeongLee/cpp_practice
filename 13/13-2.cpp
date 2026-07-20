#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, size_t size>
T SumArray(T (&arr)[size]) {
	T sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}

	return sum;
}

int main(void) {
	int arr1[5] = { 1,2,3,4,5 };
	double arr2[5] = { 1.1, 1.3, 3, 4, 5 };

	int sum1 = SumArray(arr1);
	double sum2 = SumArray(arr2);

	cout << "sum1은 " << sum1 << "입니다." << endl;
	cout << "sum2은 " << sum2 << "입니다." << endl;

}