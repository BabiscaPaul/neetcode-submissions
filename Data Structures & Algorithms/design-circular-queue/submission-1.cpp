#include <list>

class MyCircularQueue {
    int maximum_capacity;
    std::list<int> queue;
public:
    MyCircularQueue(int k) : maximum_capacity{k} {}
    
    bool enQueue(int value) {
        if (queue.size() == maximum_capacity) return false;
        queue.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if (queue.empty()) return false;
        queue.pop_front();
        return true;
    }
    
    int Front() const {
        if (queue.empty()) return -1;
        return queue.front();
    }
    
    int Rear() const {
        if (queue.empty()) return -1;
        return queue.back();
    }
    
    bool isEmpty() const {
        return queue.empty();
    }
    
    bool isFull() const {
        return !(queue.size() < maximum_capacity);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */