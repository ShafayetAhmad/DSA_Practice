#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int value) : val(value), next(nullptr) {}
};

class MyLinkedList {
private:
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        return current->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        
        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
            Node* newNode = new Node(val);
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        
        size--;
    }
};


int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);  // linked list becomes 1->2->3
    cout << "Value at index 1: " << obj->get(1) << endl; // Output: 2

    obj->deleteAtIndex(1);  // linked list becomes 1->3
    cout << "Value at index 1 after deletion: " << obj->get(1) << endl; // Output: 3

    delete obj;  // Don't forget to free the memory
    return 0;
}
