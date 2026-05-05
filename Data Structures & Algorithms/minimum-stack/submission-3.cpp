
/*

    primaryStack    = [1, 2, 3, -1]
    monotonicStack  = [1, -1]
*/

class MinStack {
private:
    std::vector<int> primaryStack; // storing the actual data 
    std::vector<int> monotonicStack; // storing the min values in deacresing order
public:    
    void push(int val) {
        primaryStack.push_back(val);
        if (monotonicStack.empty() || monotonicStack.back() >= val) {
            monotonicStack.push_back(val);
        }
    }
    
    void pop() {
        if (primaryStack.empty()) return;
        auto front = primaryStack.back();

        if (front == monotonicStack.back()) {
            monotonicStack.pop_back();
        }
        primaryStack.pop_back();
    }
    
    int top() {
        return primaryStack.back();
    }
    
    int getMin() {
        return monotonicStack.back();
    }
};
