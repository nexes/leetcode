#pragma once

#include <vector>

namespace Leet::Easy
{
    // Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    // push(x) -- Push element x onto stack.
    // pop() -- Removes the element on top of the stack.
    // top() -- Get the top element.
    // getMin() -- Retrieve the minimum element in the stack.

    // Example 1:

    // Input
    // ["MinStack","push","push","push","getMin","pop","top","getMin"]
    // [[],[-2],[0],[-3],[],[],[],[]]

    // Output
    // [null,null,null,null,-3,null,0,-2]

    // Explanation
    // MinStack minStack = new MinStack();
    // minStack.push(-2);
    // minStack.push(0);
    // minStack.push(-3);
    // minStack.getMin(); // return -3
    // minStack.pop();
    // minStack.top();    // return 0
    // minStack.getMin(); // return -2

    // Constraints:
    // Methods pop, top and getMin operations will always be called on non-empty stacks.
    class MinStack
    {
    public:
        MinStack() : stack(), top_idx(-1)
        {
        }

        void push(int x)
        {
            top_idx++;
            stack.emplace_back(x);
        }

        void pop()
        {
            top_idx--;
            stack.pop_back();
        }

        int top()
        {
            return stack.at(top_idx);
        }

        int getMin()
        {
            int min_val = stack.at(0);

            for (auto &v : stack)
                min_val = std::min(min_val, v);

            return min_val;
        }

    private:
        std::vector<int> stack;
        int top_idx;
    };
} // namespace Leet::Easy
