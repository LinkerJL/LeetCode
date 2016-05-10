#pragma once
#include <queue>
using std::queue;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queue_.push(x);
        auto size = queue_.size();
        while (--size) {
            queue_.push(queue_.front());
            queue_.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        queue_.pop();
    }

    // Get the top element.
    int top() {
        return queue_.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue_.empty();
    }
private:
    queue<int> queue_;
};
