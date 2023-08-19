#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* temp1 = head;

        while (temp != nullptr) {
            if (temp->val == val && head == temp) {
                head = head->next;
            } else if (temp->val == val) {
                temp1->next = temp->next;
                temp = temp->next;
            } else {
                temp1 = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};

int main() {
    // Create a linked list for testing
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    int val = 6; // Value to remove

    Solution obj;
    ListNode* result = obj.removeElements(head, val);

    // Print the resulting linked list
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
