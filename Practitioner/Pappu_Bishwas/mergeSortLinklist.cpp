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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ... (Your implementation of mergeTwoLists function)
    }
};

int main() {
    Solution solution;

    // Creating two sorted linked lists for merging
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    // Merging the two lists
    ListNode *mergedList = solution.mergeTwoLists(list1, list2);

    // Printing the merged list
    ListNode *current = mergedList;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Clean up the memory (deallocating the linked lists)
    current = mergedList;
    while (current != nullptr) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
