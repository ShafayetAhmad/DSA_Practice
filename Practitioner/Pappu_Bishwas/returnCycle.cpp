#include <iostream>
#include <unordered_map>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        std::unordered_map<ListNode*, int> mp;

        while (slow != NULL) {
            if (mp[slow] == 0) {
                mp[slow]++;
            } else {
                return slow;
            }
            slow = slow->next;
        }
        return NULL;
    }
};

int main() {
    // Create a linked list with a cycle for testing
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    Solution obj;
    ListNode* result = obj.detectCycle(head);

    if (result != NULL) {
        std::cout << "Cycle starts at node with value: " << result->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    return 0;
}
