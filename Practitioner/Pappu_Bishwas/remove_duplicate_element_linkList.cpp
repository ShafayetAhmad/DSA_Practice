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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* start = head;
        if (head == nullptr)
            return head;
        while (start->next != nullptr) {
            if (start->val == start->next->val) {
                start->next = start->next->next;
            } else {
                start = start->next;
            }
        }
        return head;
    }
};

int main() {
    // Create a linked list for testing
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution obj;
    ListNode* result = obj.deleteDuplicates(head);

    // Print the resulting linked list
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
