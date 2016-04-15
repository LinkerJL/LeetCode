#pragma once
#include <stack>
using std::stack;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        input_.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (output_.empty()) {
            move();
        }
        output_.pop();
    }

    // Get the front element.
    int peek(void) {
        if (output_.empty()) {
            move();
        }
        return output_.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return input_.empty() && output_.empty();
    }
private:
    // Move all of input to output.
    void move(void) {
        while (!input_.empty()) {
            output_.push(input_.top());
            input_.pop();
        }
    }

    stack<int> input_;
    stack<int> output_;
};
