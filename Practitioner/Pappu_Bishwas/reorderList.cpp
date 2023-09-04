#include <iostream>
#include <queue>
#include <stack>

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
    void reorderList(ListNode* head) {
        if (head->next == NULL)
            return;
        queue<ListNode*> qu;
        stack<ListNode*> st;
        ListNode* t1, *t2;
        t1 = head;
        t2 = head->next;
        while (t1->next != NULL && t2 != NULL && t2->next != NULL) {
            qu.push(t1);
            t1 = t1->next;
            t2 = t2->next->next;
        }
        if (t2 != NULL) {
            qu.push(t1);
            t1 = t1->next;
        }
        while (t1 != NULL) {
            st.push(t1);
            t1 = t1->next;
        }
        if (!qu.empty()) {
            head = qu.front();
            qu.pop();
            t1 = head;
            if (!st.empty()) {
                head->next = st.top();
                st.pop();
                t1 = head->next;
            }
        }

        while (!qu.empty() && !st.empty()) {
            t1->next = qu.front();
            qu.pop();
            t1 = t1->next;
            t1->next = st.top();
            t1 = t1->next;
            st.pop();
        }
        if (!qu.empty()) {
            t1->next = qu.front();
            qu.pop();
            t1 = t1->next;
        }
        if (!st.empty()) {
            t1->next = st.top();
            st.pop();
            t1 = t1->next;
        }
        t1->next = NULL;
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
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(values);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reorder the list
    solution.reorderList(head);

    cout << "Reordered Linked List: ";
    printLinkedList(head);

    return 0;
}
