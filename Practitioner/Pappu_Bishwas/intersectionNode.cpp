#include <iostream>
#include <unordered_map>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        std::unordered_map<ListNode *, int> mp;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while (temp1 != NULL)
        {
            mp[temp1]++;
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            if (mp[temp2] != 0)
                return temp2;
            temp2 = temp2->next;
        }
        return NULL;
    }
};

int main()
{
    // Create linked lists for testing
    ListNode *commonNode = new ListNode(8);
    commonNode->next = new ListNode(4);
    commonNode->next->next = new ListNode(5);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = commonNode;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = commonNode;

    Solution obj;
    ListNode *result = obj.getIntersectionNode(headA, headB);

    if (result != NULL)
    {
        std::cout << "Intersection Node Value: " << result->val << std::endl;
    }
    else
    {
        std::cout << "No Intersection Node" << std::endl;
    }

    return 0;
}
