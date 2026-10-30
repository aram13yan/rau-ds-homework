#include <iostream>
#include <forward_list>


//1
void createAndFillForwardList(int N) {
	std::forward_list<int> FL;
	for (int i = 1; i <= N; i++) {
		FL.push_front(i);
	}
	for (int x : FL) {
		std::cout << x << " ";
	}
}

//2
bool insertAfterPosition(std::forward_list<int>& fl, int pos, int value) {
	auto it = fl.begin();
	int index = 0;
	while (it != fl.end() && index < pos) {
		it++;
		index++;
	}
	if (index == pos && it != fl.end()) {
		fl.insert_after(it, value);
		return true;
	}
	return false;
}

//3 
int removeAllOccurrences(std::forward_list<int>& flist, int value) {
	int removed = 0;
	auto it = flist.before_begin();
	auto iter = flist.begin();

	while (iter != flist.end()) {
		if (*iter == value) {
			iter = flist.erase_after(it);
			removed++;
		}
		else {
			iter++;
			it++;
		}
	}
	return removed;
}

//4
void mergeSortedLists(std::forward_list<int>& fl1, std::forward_list<int>& fl2) {
	std::forward_list<int> test;

	auto it1 = fl1.begin();
	auto it2 = fl2.begin();

	while (it1 != fl1.end() && it2 != fl2.end()) {
		
		if (*it1 < *it2) {
			test.push_front(*it1);
			it1++;
		}
		else if (*it1 == *it2) {
			test.push_front(*it1);
			it1++;
		}
		else {
			test.push_front(*it2);
			it2++;
		}
	}
	
	if (it1 == fl1.end() && it2 != fl2.end()) {
		while (it2 != fl2.end()) {
			test.push_front(*it2);
			++it2;
		}
	}
	else if (it1 != fl1.end() && it2 == fl2.end()) {
		while (it1 != fl1.end()) {
			test.push_front(*it1);
			++it1;
		}
	}

	test.reverse();
	fl1 = test;
	fl2.clear();

	std::cout << "ForwardList after merge: {";
	for (int x : fl1) {
		std::cout << x << " ";
	}
	std::cout << "}";
}

int main() {
	std::forward_list<int> fl = {4, 5, 7, 8};
	//1
	createAndFillForwardList(5);

	std::cout << "\n";
	
	//2
	bool result = insertAfterPosition(fl, 3, 93);
	for (int x : fl) {
		std::cout << x << " ";
	}
	std::cout << "\nInserted:" << std::boolalpha << result << "\n";


	//3
	std::forward_list<int> flist = { 2, 2, 3, 2, 4, 2 };
	std::cout << "Removed: " << removeAllOccurrences(flist, 2) << "\n";


	//4
	std::forward_list<int> fl1 = { 1, 2, 3, 9, 10, 15 };
	std::forward_list<int> fl2 = { 3, 4, 6, 13 };

	mergeSortedLists(fl1, fl2);

	return 0;
}