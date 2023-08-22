#include <iostream>
#include <vector>
#include <utility>

class MinStack {
public:
    std::vector<std::pair<int, int>> ans;
    MinStack() {
    }
    
    void push(int val) {
        if (ans.empty())
            ans.push_back({val, val});
        else
            ans.push_back({val, std::min(ans.back().second, val)});
    }
    
    void pop() {
        ans.pop_back();
    }
    
    int top() {
        return ans.back().first;
    }
    
    int getMin() {
        return ans.back().second;
    }
};

int main() {
    MinStack stack;

    stack.push(3);
    stack.push(5);
    stack.push(2);
    stack.push(8);

    std::cout << "Top element: " << stack.top() << std::endl;
    std::cout << "Minimum element: " << stack.getMin() << std::endl;

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;
    std::cout << "Minimum element after pop: " << stack.getMin() << std::endl;

    return 0;
}
