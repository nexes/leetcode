#pragma once

#include <stack>

namespace Leet::Easy {

    // Implement the following operations of a queue using stacks.

    // push(x) -- Push element x to the back of queue.
    // pop() -- Removes the element from in front of queue.
    // peek() -- Get the front element.
    // empty() -- Return whether the queue is empty.

    // Example:

    // MyQueue queue = new MyQueue();

    // queue.push(1);
    // queue.push(2);
    // queue.peek();  // returns 1
    // queue.pop();   // returns 1
    // queue.empty(); // returns false

    // Notes:

    // You must use only standard operations of a stack -- which means only push to top,
    // peek/pop from top, size, and is empty operations are valid. Depending on your
    // language, stack may not be supported natively. You may simulate a stack by usinga
    // list or deque (double-ended queue), as long as you use only standard operations of
    // a stack. You may assume that all operations are valid (for example, no pop or peek
    // operations will be called on an empty queue).
    class MyQueue
    {
        public:
            MyQueue() : q_stack(), temp_stack() {}

            // O(n)
            void push(int x)
            {
                while (!q_stack.empty()) {
                    temp_stack.push(q_stack.top());
                    q_stack.pop();
                }

                q_stack.push(x);

                while (!temp_stack.empty()) {
                    q_stack.push(temp_stack.top());
                    temp_stack.pop();
                }
            }

            int pop()
            {
                int top = q_stack.top();
                q_stack.pop();

                return top;
            }

            int peek()
            {
                return q_stack.top();
            }

            bool empty()
            {
                return q_stack.empty();
            }

        private:
            std::stack<int> q_stack;
            std::stack<int> temp_stack;
    };
}
