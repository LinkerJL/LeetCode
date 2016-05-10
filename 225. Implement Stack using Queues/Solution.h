#pragma once
#include <queue>
using std::queue;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queue_.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        auto size = queue_.size();
        auto val = queue_.front();
        queue_.pop();
        while (--size) {
            queue_.push(val);
            val = queue_.front();
            queue_.pop();
        }
    }

    // Get the top element.
    int top() {
        auto size = queue_.size();
        auto val = 0;
        while (size--) {
            val = queue_.front();
            queue_.pop();
            queue_.push(val);
        }
        return val;
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue_.empty();
    }
private:
    queue<int> queue_;
};
