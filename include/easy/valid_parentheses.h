#pragma once

#include <string>
#include <map>
#include <stack>

namespace Leet::Easy
{

    // Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
    // determine if the input string is valid.

    // An input string is valid if:
    // Open brackets must be closed by the same type of brackets.
    // Open brackets must be closed in the correct order.
    // Note that an empty string is also considered valid.

    // Example 1:
    // Input: "()"
    // Output: true

    // Example 2:
    // Input: "()[]{}"
    // Output: true

    // Example 3:
    // Input: "(]"
    // Output: false

    // Example 4:
    // Input: "([)]"
    // Output: false

    // Example 5:
    // Input: "{[]}"
    // Output: true
    struct Parentheses
    {
        bool isValid(std::string s)
        {
            std::stack<char> paren_stack;
            std::map<char, char> paren_map{{')', '('},
                                           {']', '['},
                                           {'}', '{'}};

            for (const auto &c : s)
            {
                if (paren_map.find(c) != paren_map.end())
                {
                    if (!paren_stack.empty() && paren_stack.top() == paren_map.at(c))
                        paren_stack.pop();
                    else
                        return false;
                }
                else
                {
                    paren_stack.push(c);
                }
            }

            return paren_stack.empty();
        }
    };
} // namespace Leet::Easy
