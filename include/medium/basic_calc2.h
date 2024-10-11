#pragma once

#include <stack>
#include <string>

using std::stack;
using std::string;

namespace Leet::Medium {
    // Given a string s which represents an expression, evaluate this expression and
    // return its value. The integer division should truncate toward zero. You may assume
    // that the given expression is always valid. All intermediate results will be in the
    // range of [-231, 231 - 1].

    // Note: You are not allowed to use any built-in function which evaluates strings as
    // mathematical expressions, such as eval().

    // Example 1:
    // Input: s = "3+2*2"
    // Output: 7

    // Example 2:
    // Input: s = " 3/2 "
    // Output: 1

    // Example 3:
    // Input: s = " 3+5 / 2 "
    // Output: 5

    // Constraints:
    // 1 <= s.length <= 3 * 105
    // s consists of integers and operators ('+', '-', '*', '/') separated by some number
    // of spaces. s represents a valid expression. All the integers in the expression are
    // non-negative integers in the range [0, 231 - 1]. The answer is guaranteed to fit in
    // a 32-bit integer.
    struct BasicCalc2
    {
        int calculate(string s)
        {
            stack<int> numStk;
            int digit = 0;
            char op = '!';

            for (char c : s) {
                if (std::isspace(c))
                    continue;

                if (std::isdigit(c)) {
                    digit *= 10;
                    digit += (c - '0');
                } else {
                    if (op == '!') {
                        numStk.push(digit);
                        digit = 0;
                        op = c;
                    } else {
                        if (op == '+')
                            numStk.push(digit);
                        else if (op == '-')
                            numStk.push(-digit);
                        else if (op == '*') {
                            int a = numStk.top();
                            numStk.pop();
                            numStk.push(a * digit);
                        } else if (op == '/' && digit != 0) {
                            int a = numStk.top();
                            numStk.pop();
                            numStk.push(a / digit);
                        }

                        digit = 0;
                        op = c;
                    }
                }
            }

            if (numStk.empty())
                return digit;

            int result = 0;
            int a = numStk.top();
            numStk.pop();

            if (op == '+')
                numStk.push(a + digit);
            if (op == '-')
                numStk.push(a - digit);
            if (op == '*')
                numStk.push(a * digit);
            if (op == '/')
                numStk.push(a / digit);

            while (!numStk.empty()) {
                result += numStk.top();
                numStk.pop();
            }

            return result;
        }
    };
}  // namespace Leet::Medium