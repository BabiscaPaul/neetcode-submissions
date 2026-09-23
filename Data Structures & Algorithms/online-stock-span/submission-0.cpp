#include <stack>

class StockSpanner {
public:

    int next(int price) {
        int count = 1;
        
        while (!decr_stack.empty() && price >= decr_stack.top().curr_stock_price) {
            count += decr_stack.top().span;
            decr_stack.pop();
        }

        decr_stack.push(StackPair{price, count});

        return count;
    }

private:
    struct StackPair {
        int curr_stock_price;
        int span;
    };

    std::stack<StackPair> decr_stack;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */