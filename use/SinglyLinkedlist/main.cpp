#include <iostream>

struct ListNode {
	int data;
	ListNode* next;

	explicit ListNode(int val) : data(val), next(nullptr) {}
};


//1
ListNode* findMiddle(ListNode* head) {
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//2
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            return true;
        }
    }
    
    return false;
}
//3
void deleteDuplicates(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            ListNode* temp = current->next;
            current->next = temp->next; 
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

int main() {
        // 1. Find Middle
        std::cout << "=== Find Middle ===\n";

        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        head->next->next->next->next->next = new ListNode(6);

        ListNode* middle = findMiddle(head);

        if (middle != nullptr) {
            std::cout << "Middle: " << middle->data << "\n";
        }

        // 2. Has Cycle
        std::cout << "\n=== Has Cycle ===\n";

        std::cout << "Without cycle: "
            << std::boolalpha << hasCycle(head) << "\n";

        ListNode* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = head->next->next;

        std::cout << "With cycle: "
            << hasCycle(head) << "\n";

        last->next = nullptr;

        // 3. Delete Duplicates
        std::cout << "\n=== Delete Duplicates ===\n";

        ListNode* duplicates = new ListNode(1);
        duplicates->next = new ListNode(1);
        duplicates->next->next = new ListNode(2);
        duplicates->next->next->next = new ListNode(3);
        duplicates->next->next->next->next = new ListNode(3);

        std::cout << "Before: ";
        for (ListNode* p = duplicates; p != nullptr; p = p->next) {
            std::cout << p->data << " ";
        }
        std::cout << "\n";

        deleteDuplicates(duplicates);

        std::cout << "After: ";
        for (ListNode* p = duplicates; p != nullptr; p = p->next) {
            std::cout << p->data << " ";
        }
        std::cout << "\n";

        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        while (duplicates != nullptr) {
            ListNode* temp = duplicates;
            duplicates = duplicates->next;
            delete temp;
        }

        return 0;
    }
