#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *current = head, *prev = head;
        int flag = 0;
        while (current->next != nullptr)
        {
            if (current->val == current->next->val)
            {
                ListNode *duplicate = current;
                if (prev == current)
                    prev = head = current->next;
                else
                    prev->next = current->next;
                flag = 1;
                current = current->next;
                // prev=prev->next;
                //  current->next = current->next->next;
                delete duplicate;
            }
            else if (flag == 1)
            {
                ListNode *duplicate = current;
                if (prev == current)
                    prev = head = current->next;
                else
                    prev->next = current->next;
                flag = 0;
                current = current->next;
                delete duplicate;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        if (flag == 1)
        {
            ListNode *duplicate = current;
            if (prev == current)
                prev = head = current->next;
            else
                prev->next = current->next;
            flag = 0;
            current = current->next;
            delete duplicate;
        }

        return head;
    }
};

// Utility function to print a linked list
void printLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Create a linked list for testing
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution obj;
    ListNode *result = obj.deleteDuplicates(head);

    // Print the resulting linked list
    printLinkedList(result);

    return 0;
}
