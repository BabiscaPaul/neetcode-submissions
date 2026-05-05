#include <deque>

class MovingAverage {
private:
    int fixedSize; 
    int sum = 0;
    std::deque<int> deque;
public:
    MovingAverage(int size): fixedSize(size) {}
    
    double next(int val) {
        if (deque.size() >= fixedSize) {
            sum -= deque.front();
            deque.pop_front();
        }
        deque.push_back(val);
        sum += val;

        return static_cast<double>(sum) / deque.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
