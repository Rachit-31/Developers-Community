#include <iostream>
using namespace std;

// Definition for a linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (!head || !head->next) {
        return false; // If the list is empty or has only one element, no cycle
    }

    ListNode *tortoise = head; 
    ListNode *hare = head;     // Moves two steps at a time

    while (hare && hare->next) {
        tortoise = tortoise->next;       // Move tortoise one step
        hare = hare->next->next;         // Move hare two steps

        if (tortoise == hare) {          // Cycle detected
            return true;
        }
    }
    return false; // No cycle found
}

int main() {
    // Creating a linked list: 3 -> 2 -> 0 -> -4 (cycle back to 2)
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creating a cycle

    if (hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    return 0;
}
