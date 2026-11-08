#include <iostream>

struct ListNode {
	int data;
	ListNode* next;
	ListNode* prev;

	explicit ListNode(int value) : data(value), 
		next(nullptr), prev(nullptr) {}
};

//3
void erase(ListNode* node) {
	if (node == nullptr) {
		return;
	}
	if (node->prev != nullptr) {
		node->prev->next = node->next;
	}
	if (node->next != nullptr) {
		node->next->prev = node->prev;
	}
	delete node;
}

//4
ListNode* reverse(ListNode* head) {
	ListNode* current = head;
	ListNode* newHead = nullptr;

	while (current != nullptr) {
		ListNode* temp = current->prev;
		current->prev = current->next;
		current->next = temp;

		newHead = current;
		current = current->prev;

	}
	return newHead;
}


//5
void sort(ListNode* head) {
	if (head == nullptr) {
		return;
	}

	bool swapped = true;

	while (swapped) {
		swapped = false;
		ListNode* current = head;

		while (current != nullptr && current->next != nullptr) {
			if (current->data > current->next->data) {
				int temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;

				swapped = true;
			}

			current = current->next;
		}
	}
}


int main() {
    ListNode* head = new ListNode(5);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(8);
    ListNode* fourth = new ListNode(1);
    ListNode* fifth = new ListNode(4);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    // 3. Erase
    std::cout << "=== Erase ===\n";
    std::cout << "Before: ";

    for (ListNode* current = head; current != nullptr; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << "\n";

    erase(third);

    std::cout << "After: ";
    for (ListNode* current = head; current != nullptr; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << "\n";

    // 4. Reverse
    std::cout << "\n=== Reverse ===\n";

    head = reverse(head);

    for (ListNode* current = head; current != nullptr; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << "\n";

    // 5. Bubble Sort
    std::cout << "\n=== Bubble Sort ===\n";

    sort(head);

    for (ListNode* current = head; current != nullptr; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << "\n";

    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
