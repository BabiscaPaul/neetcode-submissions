#include <stack>

/*
    stack = [3, 4, 2]
    min_monotonic_stack = [3, 2]
*/

class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> monotonic;
public:
    MinStack() = default;
    
    void push(int val) {
        stack.push(val);
        if (monotonic.empty() || monotonic.top() >= val) 
            monotonic.push(val);
    }
    
    void pop() {
        int top = stack.top();
        
        if (top == monotonic.top())
            monotonic.pop();
        
        stack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return monotonic.top();
    }
};
