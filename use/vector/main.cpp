#include <iostream>
#include <string>
#include <vector>

void createAndFillVector(int n) {
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
		std::cout << a[i] << std::endl;
	}
	std::cout << "Size:" << " " << a.size() << std::endl;
	std::cout << "Capacity:" << " " << a.capacity() << std::endl;
}

void workWithEmptyVector() {
	std::vector<int> b;
	for (int i = 0; i < 10; i++) {
		b.push_back(i + 1);
		std::cout << "Size:" << " " << b.size() << std::endl;
		std::cout << "Capacity:" << " " << b.capacity() << std::endl;
	}
	for (int i = 0; i < b.size(); i++) {
		std::cout << b[i] << std::endl;
	}
}

std::vector<int> createVectorFromInput() {
	std::vector<int> c;
	int input;
	std::cout << "Enter numbers (0 to stop): ";
	while (std::cin >> input && input != 0) {
		c.push_back(input);
	}
	return c;
}

int removeElementsGreaterThan(std::vector<int>& d, int treshold) {
	int removed_count = 0;
	while (d.empty() == false && d.back() > treshold) {
		d.pop_back();
		removed_count++;
	}

	return removed_count;
}

void manageCapacity(std::vector<int>& e) {
	std::cout << "Before - Size: " << e.size() << " Capacity: " << e.capacity() << std::endl;
	e.reserve(e.capacity() + 500);

	for (int i = 1; i <= 500; i++) {
		e.push_back(i);
	}

	std::cout << "After - Size: " << e.size() << " Capacity: " << e.capacity() << std::endl;
}

template<typename T>
void resizeVector(std::vector<T>& f, int new_size, T member) {

	std::cout << "Before:" << std::endl;
	for (int i = 0; i < f.size(); i++) {
		std::cout << f[i] << std::endl;
	}

	f.resize(new_size, member);

	std::cout << "After:" << std::endl;
	for (int i = 0; i < f.size(); i++) {
		std::cout << f[i] << std::endl;
	}
}

std::vector<int> mergeSortedVectors(const std::vector<int>& v1, const std::vector<int>& v2) {
	std::vector<int> merged;
	int i = 0;
	int j = 0;

	while (i < v1.size() && j < v2.size()) {
		if (v1[i] < v2[j]) {
			merged.push_back(v1[i]);
			i++;
		}
		else {
			merged.push_back(v2[j]);
			j++;
		}
	}
	while (i < v1.size()) {
		merged.push_back(v1[i]);
		i++;
	}
	while (j < v2.size()) {
		merged.push_back(v2[j]);
		j++;
	}
	return merged;
}

int findSubsequence(const std::vector<int>& k1, const std::vector<int>& k2) {
	if (k1.empty()) {
		return 0;
	}
	if (k1.size() < k2.size()) {
		return -1;
	}

	for (int i = 0; i <= k1.size() - k2.size(); i++) {
		bool found = true;
		for (int j = 0; j < k2.size(); j++) {
			if (k1[i + j] != k2[j]) {
				found = false;
				break;
			}
		}
		if (found) return i;
	}
	return -1;
}

std::vector<std::vector<int>> groupAdjacent(const std::vector<int>& vec) {
	std::vector<std::vector<int>> groups;
	if (vec.empty()) return groups;

	std::vector<int> current_group;
	current_group.push_back(vec[0]);

	for (int i = 1; i < vec.size(); i++) {
		if (vec[i - 1] == vec[i]) {
			current_group.push_back(vec[i]);
		}
		else {
			groups.push_back(current_group);
			current_group.clear();
			current_group.push_back(vec[i]);
		}
	}
	groups.push_back(current_group);
	return groups;
}

template<typename Y, typename Predicate>
std::vector<Y> filterVector(const std::vector<Y>& vector, Predicate pred) {
	std::vector<Y> filtered;
	for (int i = 0; i < vector.size(); i++) {
		if (pred(vector[i])) {
			filtered.push_back(vector[i]);
		}
	}
	return filtered;
}

int main() {
	std::cout << "=== Test 1: createAndFillVector ===" << std::endl;
	createAndFillVector(5);

	std::cout << "\n=== Test 2: workWithEmptyVector ===" << std::endl;
	workWithEmptyVector();

	std::cout << "\n=== Test 3: removeElementsGreaterThan ===" << std::endl;
	std::vector<int> d = { 1, 2, 3, 10, 20, 30 };
	int removed = removeElementsGreaterThan(d, 5);
	std::cout << "Removed count: " << removed << " (remaining size: " << d.size() << ")" << std::endl;

	std::cout << "\n=== Test 4: manageCapacity ===" << std::endl;
	std::vector<int> e = { 1, 2, 3 };
	manageCapacity(e);

	std::cout << "\n=== Test 5: resizeVector ===" << std::endl;
	std::vector<int> f = { 1, 2, 3 };
	resizeVector(f, 6, 99);
	std::cout << std::endl;

	std::cout << "\n=== Test 6: mergeSortedVectors ===" << std::endl;
	std::vector<int> v1 = { 1, 3, 5 };
	std::vector<int> v2 = { 2, 4, 6 };
	std::vector<int> merged = mergeSortedVectors(v1, v2);
	std::cout << "Merged: ";
	for (int x : merged) std::cout << x << " ";
	std::cout << std::endl;

	std::cout << "\n=== Test 7: findSubsequence ===" << std::endl;
	std::vector<int> k1 = { 1, 2, 3, 4, 5 };
	std::vector<int> k2 = { 3, 4 };
	std::cout << "Found at index: " << findSubsequence(k1, k2) << std::endl;

	std::cout << "\n=== Test 8: groupAdjacent ===" << std::endl;
	std::vector<int> vec = { 1, 1, 2, 3, 3, 3, 4 };
	auto groups = groupAdjacent(vec);
	for (const auto& group : groups) {
		std::cout << "[ ";
		for (int x : group) std::cout << x << " ";
		std::cout << "] ";
	}
	std::cout << std::endl;

	std::cout << "\n=== Test 9: filterVector ===" << std::endl;
	std::vector<int> to_filter = { 1, 2, 3, 4, 5, 6 };
	auto filtered = filterVector(to_filter, [](int x) { return x % 2 == 0; });
	std::cout << "Even numbers: ";
	for (int x : filtered) std::cout << x << " ";
	std::cout << std::endl;

	return 0;
}