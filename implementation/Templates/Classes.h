#pragma once
#include <iostream>
#include <string>



template <typename T1, typename T2>
class Pair {
private:
	T1 first;
	T2 second;

public:
	Pair(T1 a, T2 b) {
		first = a;
		second = b;
	}

	void print() {
		std::cout << first << "," << second << std::endl;
	}
};

template <typename T, int N>
class FixedArray {
private:
	T data[N];

public:
	void set(int index, T value) {
		if (index >= 0 && index < N) {
			data[index] = value;
		}
		else {
			std::cout << "Error" << std::endl;
		}
	}
	T get(int index) {
		if (index >= 0 && index < N) {
			return data[index];
		}
		else {
			return T();
		}
	}
	int size() {
		return N;
	}
};

template <typename T, int N, int M>
class Matrix {
private:
	T data[N][M];

public:
	Matrix() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				data[i][j] = T();
			}
		}
	}
	void set(int row, int col, T value) {
		if (row >= 0 && row < N && col >= 0 && col < M) {
			data[row][col] = value;
		}
	}

	T get(int row, int col) {
		if (row >= 0 && row < N && col >= 0 && col < M) {
			return data[row][col];
		}
		else {
			return T();
		}
	}

	void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				std::cout << data[i][j] << "\t";
			}
			std::cout << std::endl;
		}
	}

	Matrix<T, N, M> operator+(const Matrix < T, N, M>& other) {
		Matrix<T, N, M> result;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				result.data[i][j] = this->data[i][j] + other.data[i][j];
			}
		}
		return result;
	}

};

template <typename T>
class Range {
private:
	T start;
	T end;

public:
	Range(T s, T e) {
		start = s;
		end = e;
	}

	bool contains(const T& value) {
		return (value >= start && value <= end);
	}

	T length() {
		return (end - start);
	}

	void print() {
		std::cout << "[" << start << "," << end << "]" << std::endl;
	}
};

template <typename T>
void printValue(T value) {
	std::cout << value << std::endl;
}

template <>
void printValue<bool>(bool value) {
	if (value == true) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
}
