#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head->next;  // Start fast pointer ahead by 1 step
        
        while (fast != NULL && fast->next != NULL) {
            if (slow == fast)
                return true;
            
            slow = slow->next;
            fast = fast->next->next;  // Move fast pointer by 2 steps
        }
        
        return false;
    }
};

int main() {
    // Creating a linked list with a cycle for demonstration
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;  // Creating a cycle
    
    Solution solution;
    bool hasCycle = solution.hasCycle(head);
    
    if (hasCycle)
        std::cout << "The linked list has a cycle." << std::endl;
    else
        std::cout << "The linked list does not have a cycle." << std::endl;
    
    // Clean up the memory (deallocating the linked list)
    ListNode *current = head;
    while (current != NULL) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}
