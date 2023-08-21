#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* t1, *t2, *temp;
        t1 = head;
        head = head->next;
        t2 = head->next;
        head->next = t1;
        t1->next = t2;
        
        while (t2 != NULL && t2->next != NULL) {
            temp = t1->next;
            t1->next = t2->next;
            t2 = t2->next->next;
            t1->next->next = temp;
            temp->next = t2;
            t1 = t1->next->next;
        }
        
        return head;
    }
};

// Helper function to create a linked list
ListNode* createLinkedList(vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Create a sample linked list
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(values);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Swap adjacent nodes
    ListNode* newHead = solution.swapPairs(head);

    cout << "Linked List after Swapping Pairs: ";
    printLinkedList(newHead);

    return 0;
}
