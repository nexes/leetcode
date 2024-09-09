#pragma once

#include <stack>
#include <string>

using std::stack;
using std::string;

namespace Leet::Medium {
    // Given a string s containing only three types of characters: '(', ')' and '*',
    // return true if s is valid. The following rules define a valid string:

    // Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    // Any right parenthesis ')' must have a corresponding left parenthesis '('.
    // Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    // '*' could be treated as a single right parenthesis ')' or a single left parenthesis
    // '(' or an empty string "".

    // Example 1:
    // Input: s = "()"
    // Output: true

    // Example 2:
    // Input: s = "(*)"
    // Output: true

    // Example 3:
    // Input: s = "(*))"
    // Output: true

    // Constraints:
    // 1 <= s.length <= 100
    // s[i] is '(', ')' or '*'.
    struct ValidParenString
    {
        // time: O(n)
        // space: O(1)
        bool checkValidString_better_memeory(string s)
        {
            // go from left to right, see if we can match every left paren '('
            int open = 0;
            int asterix = 0;
            for (int i = 0; i < s.length(); i++) {
                switch (s[i]) {
                case '(':
                    open++;
                    break;
                case '*':
                    asterix++;
                    break;
                case ')':
                    if (open > 0)
                        open--;
                    else if (asterix > 0)
                        asterix--;
                    else
                        return false;
                    break;
                }
            }

            // go from right to left, see if we can match every right paren ')'
            open = 0;
            asterix = 0;
            for (int i = s.length() - 1; i >= 0; i--) {
                switch (s[i]) {
                case ')':
                    open++;
                    break;
                case '*':
                    asterix++;
                    break;
                case '(':
                    if (open > 0)
                        open--;
                    else if (asterix > 0)
                        asterix--;
                    else
                        return false;
                    break;
                }
            }

            return true;
        }

        // time: O(n)
        // space: O(n)
        bool checkValidString(string s)
        {
            stack<int> open;
            stack<int> astrix;

            for (int i = 0; i < s.length(); i++) {
                switch (s[i]) {
                case '(':
                    open.push(i);
                    break;
                case '*':
                    astrix.push(i);
                    break;
                case ')':
                    if (!open.empty())
                        open.pop();
                    else if (!astrix.empty())
                        astrix.pop();
                    else
                        return false;
                    break;
                }
            }

            while (!open.empty() && !astrix.empty()) {
                if (open.top() > astrix.top())
                    return false;
                open.pop();
                astrix.pop();
            }

            return open.empty();
        }
    };
}  // namespace Leet::Medium