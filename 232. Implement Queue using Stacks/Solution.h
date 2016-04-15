#pragma once
#include <stack>
using std::stack;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while (!master_.empty()) {
            slave_.push(master_.top());
            master_.pop();
        }
        master_.push(x);
        while (!slave_.empty()) {
            master_.push(slave_.top());
            slave_.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        master_.pop();
    }

    // Get the front element.
    int peek(void) {
        return master_.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return master_.empty();
    }
private:
    stack<int> master_;
    stack<int> slave_;
};
