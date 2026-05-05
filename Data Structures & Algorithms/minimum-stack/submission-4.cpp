#include <vector>

class MinStack {
private:
    std::vector<int> stack;
    std::vector<int> mono_dec_stack;
public:    
    void push(int val) {
        stack.push_back(val);
        if (mono_dec_stack.empty() || val <= mono_dec_stack.back())
            mono_dec_stack.push_back(val);
    }
    
    void pop() {
        int top = stack.back();
        stack.pop_back();

        if (mono_dec_stack.back() == top)
            mono_dec_stack.pop_back();
    }
    
    int top() const {
        return stack.back();
    }
    
    int getMin() const {
        return mono_dec_stack.back();
    }
};