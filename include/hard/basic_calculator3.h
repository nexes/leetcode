#pragma once

#include <stack>
#include <string>

using std::stack;
using std::string;

namespace Leet::Hard {
    // Implement a basic calculator to evaluate a simple expression string.
    // The expression string contains only non-negative integers, '+', '-', '*', '/'
    // operators, and open '(' and closing parentheses ')'. The integer division should
    // truncate toward zero. You may assume that the given expression is always valid. All
    // intermediate results will be in the range of [-231, 231 - 1].

    // Note: You are not allowed to use any built-in function which evaluates strings as
    // mathematical expressions, such as eval().

    // Example 1:
    // Input: s = "1+1"
    // Output: 2

    // Example 2:
    // Input: s = "6-4/2"
    // Output: 4

    // Example 3:
    // Input: s = "2*(5+5*2)/3+(6/2+8)"
    // Output: 21

    // Constraints:
    // 1 <= s <= 104
    // s consists of digits, '+', '-', '*', '/', '(', and ')'.
    // s is a valid expression.
    struct BasicCalc3
    {
        // convert to a postfix express first. using '_'  to seperate digits so we know if
        // we're evaluating multi digit numbers
        string convertPostfix(string s)
        {
            string postfix = "";
            string digit = "_";
            stack<char> opStack;

            for (char c : s) {
                switch (c) {
                case '+':
                case '-':
                    if (digit.length() > 1) {
                        postfix.append(digit);
                        digit = "_";
                    }
                    while (!opStack.empty() && opStack.top() != '(') {
                        postfix.push_back(opStack.top());
                        opStack.pop();
                    }
                    opStack.push(c);
                    break;
                case '/':
                case '*':
                    if (digit.length() > 1) {
                        postfix.append(digit);
                        digit = "_";
                    }
                    while (!opStack.empty() &&
                           (opStack.top() == '/' || opStack.top() == '*')) {
                        postfix.push_back(opStack.top());
                        opStack.pop();
                    }
                    opStack.push(c);
                    break;
                case '(':
                    if (digit.length() > 1) {
                        postfix.append(digit);
                        digit = "_";
                    }
                    opStack.push('(');
                    break;
                case ')':
                    if (digit.length() > 1) {
                        postfix.append(digit);
                        digit = "_";
                    }
                    while (!opStack.empty() && opStack.top() != '(') {
                        postfix.push_back(opStack.top());
                        opStack.pop();
                    }
                    opStack.pop();
                    break;
                default:
                    // this is a digit
                    digit.push_back(c);
                    break;
                };
            }

            if (digit.length() > 1)
                postfix.append(digit);

            while (!opStack.empty()) {
                postfix.push_back(opStack.top());
                opStack.pop();
            }

            return postfix;
        }

        int calculate(string s)
        {
            stack<int> eval;
            string postfix = convertPostfix(s);

            bool isDigit = false;
            int digit = 0;

            for (char c : postfix) {
                switch (c) {
                case '_':
                    if (isDigit) {
                        eval.push(digit);
                        digit = 0;
                    }
                    isDigit = true;
                    break;
                case '+':
                case '-':
                case '*':
                case '/': {
                    int rhs = digit;
                    if (!isDigit) {
                        rhs = eval.top();
                        eval.pop();
                    }
                    int lhs = eval.top();
                    int result;
                    eval.pop();

                    if (c == '+')
                        result = lhs + rhs;
                    if (c == '-')
                        result = lhs - rhs;
                    if (c == '*')
                        result = lhs * rhs;
                    if (c == '/' && rhs != 0)
                        result = lhs / rhs;
                    eval.push(result);
                    digit = 0;
                    isDigit = false;
                } break;
                default:
                    digit *= 10;
                    digit += (c - '0');
                    break;
                };
            }

            return isDigit ? digit : eval.top();
        }
    };
}  // namespace Leet::Hard