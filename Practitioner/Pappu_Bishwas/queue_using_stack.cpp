#include <iostream>
#include <stack>

class MyQueue {
public:
    std::stack<int> ans;
    std::stack<int> temp;

    MyQueue() {
    }

    void push(int x) {
        ans.push(x);
    }

    int pop() {
        while (!ans.empty()) {
            temp.push(ans.top());
            ans.pop();
        }
        int p = temp.top();
        temp.pop();
        while (!temp.empty()) {
            ans.push(temp.top());
            temp.pop();
        }
        return p;
    }

    int peek() {
        while (!ans.empty()) {
            temp.push(ans.top());
            ans.pop();
        }
        int p = temp.top();
        while (!temp.empty()) {
            ans.push(temp.top());
            temp.pop();
        }
        return p;
    }

    bool empty() {
        return ans.empty();
    }
};

int main() {
    MyQueue queue;

    queue.push(3);
    queue.push(5);
    queue.push(2);

    std::cout << "Front element: " << queue.peek() << std::endl;
    std::cout << "Removed element: " << queue.pop() << std::endl;
    std::cout << "Front element after pop: " << queue.peek() << std::endl;
    std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
