#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        this->val = 0;
        this->next = nullptr;
    }
    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
    ListNode(int val, ListNode *next)
    {
        this->val = val;
        this->next = next;
    }
};

ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

    // ListNode *prev = nullptr;
    // ListNode *curr = head;

    // while (curr != nullptr)
    // {
    //     ListNode *nextTemp = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = nextTemp;
    // }

    // return prev;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *current = head;

    for (int i = 2; i <= 4; ++i)
    {
        current->next = new ListNode(i);
        current = current->next;
    }
    head = reverse(head);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
