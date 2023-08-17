#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        ListNode *prev, *temp;
        temp = head;
        prev = NULL;
        while (head != NULL) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        head = prev;
        return head;
    }
};

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print the original linked list
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;

    // Reverse the linked list
    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    // Print the reversed linked list
    current = reversedHead;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;

    return 0;
}
