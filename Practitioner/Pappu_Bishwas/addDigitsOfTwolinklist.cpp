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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1, *ptr2, *head, *temp = l1;
        head = l1;
        ptr1 = l1;
        ptr2 = l2;
        int sum = 0, mod = 0;
        while (ptr1 != nullptr && ptr2 != nullptr) {
            sum = ptr1->val + ptr2->val + sum;
            if (sum > 9) {
                mod = sum % 10;
                sum = sum / 10;
                ptr1->val = mod;
            } else {
                ptr1->val = sum;
                sum = 0;
            }
            temp = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (ptr2 != nullptr) {
            temp->next = ptr2;
            while (sum > 0 && ptr2 != nullptr) {
                sum = sum + ptr2->val;
                if (sum > 9) {
                    ptr2->val = sum % 10;
                    sum = sum / 10;
                } else {
                    ptr2->val = sum;
                    sum = 0;
                }
                temp = ptr2;
                ptr2 = ptr2->next;
            }
            if (sum > 0) {
                ListNode* p = new ListNode(sum);
                temp->next = p;
            }
        } else {
            while (sum > 0 && ptr1 != nullptr) {
                sum = sum + ptr1->val;
                if (sum > 9) {
                    ptr1->val = sum % 10;
                    sum = sum / 10;
                } else {
                    ptr1->val = sum;
                    sum = 0;
                }
                temp = ptr1;
                ptr1 = ptr1->next;
            }
            if (sum > 0) {
                ListNode* p = new ListNode(sum);
                temp->next = p;
            }
        }
        return head;
    }
};

// Utility function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create linked lists for testing
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution obj;
    ListNode* result = obj.addTwoNumbers(l1, l2);

    // Print the resulting linked list
    printLinkedList(result);

    return 0;
}
