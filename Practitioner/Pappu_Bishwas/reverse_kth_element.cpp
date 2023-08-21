#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* start, int m) {
        if (start->next == nullptr || m == 1)
            return start;

        ListNode *t3, *t1, *t2, *q, *prev, *p;
        int i = 1, k, c = 1;
        t3 = t1 = p = start;

        while (t1 != nullptr) {
            i = m;
            k = m;
            while (i > 0 && p != nullptr) {
                p = p->next;
                i--;
            }
            if (i != 0)
                break;
            if (c == 1) {
                prev = p;
                t3 = t1;
                while (k > 0 && t1 != nullptr) {
                    t2 = t1->next;
                    t1->next = prev;
                    prev = t1;
                    t1 = t2;
                    k--;
                }
                start = prev;
                c++;
            } else {
                prev = p;
                t1 = t3->next;
                q = t3->next;
                while (k > 0 && t1 != nullptr) {
                    t2 = t1->next;
                    t1->next = prev;
                    prev = t1;
                    t1 = t2;
                    k--;
                }
                t3->next = prev;
                t3 = q;
            }
        }
        return start;
    }
};

// Helper function to create a linked list
ListNode* createLinkedList(vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Create a sample linked list
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head = createLinkedList(values);

    cout << "Original Linked List: ";
    printLinkedList(head);

    int k = 3; // Number of nodes in each group
    ListNode* newHead = solution.reverseKGroup(head, k);

    cout << "Linked List after Reversing K-Group Segments: ";
    printLinkedList(newHead);

    return 0;
}
