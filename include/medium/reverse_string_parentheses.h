#pragma once

#include <algorithm>
#include <stack>
#include <string>

namespace Leet::Medium {
    // You are given a string s that consists of lower case English letters and brackets.
    // Reverse the strings in each pair of matching parentheses, starting from the
    // innermost one.

    // Your result should not contain any brackets.

    // Example 1:
    // Input: s = "(abcd)"
    // Output: "dcba"

    // Example 2:
    // Input: s = "(u(love)i)"
    // Output: "iloveu"
    // Explanation: The substring "love" is reversed first, then the whole string is
    // reversed.

    // Example 3:
    // Input: s = "(ed(et(oc))el)"
    // Output: "leetcode"
    // Explanation: First, we reverse the substring "oc", then "etco", and finally, the
    // whole string.

    // Constraints:
    // 1 <= s.length <= 2000
    // s only contains lower case English characters and parentheses.
    // It is guaranteed that all parentheses are balanced.
    struct ReverseStringParens
    {
        std::string reverseParentheses(std::string s)
        {
            std::stack<std::string> st;
            std::string curr = "";

            for (char c : s) {
                if (c == '(') {
                    st.push(curr);
                    curr = "";

                } else if (c == ')') {
                    std::string t = st.top();
                    st.pop();
                    std::reverse(curr.begin(), curr.end());

                    curr = t.append(curr);

                } else {
                    curr.push_back(c);
                }
            }

            return curr;
        }
    };
}  // namespace Leet::Medium