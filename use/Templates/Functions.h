#pragma once
#include <iostream>
#include <vector>

template <typename T>
void printElement(T val) {
	std::cout << val << std::endl;
}

template <typename T>
void mySwap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T sumArray(T* arr, int size) {
	T sum = T();
	for (int i = 0; i <= size; i++) {
		sum += arr[i];
	}
	return sum;
}

template <typename T, typename Predicate>
std::vector<T> filter(T* arr, int size, Predicate pred) {
	std::vector<T> result;
	for (int i = 0; i < size; i++) {
		if (pred(arr[i])) {
			result.push_back(arr[i]);
		}
	}
	return result;
}

template <typename T>
int linearSearch(const std::vector<T>& vector, T target) {
	for (int i = 0; i < vector.size(); i++) {
		if (vector[i] == target) {
			return i;
		}
	}
	return -1;
}