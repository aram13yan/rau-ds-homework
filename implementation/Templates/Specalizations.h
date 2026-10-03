#pragma once
#include <iostream>
#include <string>
#include <cstring>


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

template <>
void printValue<char*>(char* value) {
	std::cout << "[" << value << "]" << std::endl;
}

template <typename T>
bool isEqual(T value1, T value2) {
	return value1 = value2;
}

template <>
bool isEqual<const char*>(const char* a, const char* b) {
	return (std::strcmp(a, b) == 0);
}

