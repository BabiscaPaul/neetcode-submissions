#include <algorithm>
#include <stack>
#include <vector>

/*
    [5, 10, 20, 1, 20]
    [4, 1, 1]
*/

class MinStack {
    private:
        std::vector<int> stack;
        std::stack<int> monotonic_stack;
    public:
        void push(int val) {
            stack.push_back(val);
            if (monotonic_stack.empty() || monotonic_stack.top() >= val)
                monotonic_stack.push(val);
        }
        
        void pop() {
            if (stack.empty()) return;

            int top = stack.back();
            if (monotonic_stack.top() == top) monotonic_stack.pop();

            stack.pop_back();
        }
        
        int top() {
            return stack.back();
        }
        
        int getMin() {
            return monotonic_stack.top();
        }
};
