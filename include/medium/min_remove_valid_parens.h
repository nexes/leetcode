#pragma once

#include <stack>
#include <string>
#include <unordered_set>

using std::stack;
using std::string;
using std::unordered_set;

namespace Leet::Medium {
    // Given a string s of '(' , ')' and lowercase English characters.
    // Your task is to remove the minimum number of parentheses ( '(' or ')', in any
    // positions ) so that the resulting parentheses string is valid and return any valid
    // string.

    // Formally, a parentheses string is valid if and only if:

    // It is the empty string, contains only lowercase characters, or
    // It can be written as AB (A concatenated with B), where A and B are valid strings,
    // or It can be written as (A), where A is a valid string.

    // Example 1:
    // Input: s = "lee(t(c)o)de)"
    // Output: "lee(t(c)o)de"
    // Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

    // Example 2:
    // Input: s = "a)b(c)d"
    // Output: "ab(c)d"

    // Example 3:
    // Input: s = "))(("
    // Output: ""
    // Explanation: An empty string is also valid.

    // Constraints:
    // 1 <= s.length <= 105
    // s[i] is either '(' , ')', or lowercase English letter.
    struct MinRemoveValidParen
    {
        string minRemoveToMakeValid(string s)
        {
            stack<std::pair<char, int>> parenStk;
            unordered_set<int> skipIdx;
            string balanced = "";

            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '(')
                    parenStk.push({'(', i});
                if (s[i] == ')') {
                    if (!parenStk.empty() && parenStk.top().first == '(')
                        parenStk.pop();
                    else
                        parenStk.push({')', i});
                }
            }

            while (!parenStk.empty()) {
                skipIdx.insert(parenStk.top().second);
                parenStk.pop();
            }

            for (int i = 0; i < s.length(); i++) {
                if (!skipIdx.count(i))
                    balanced.push_back(s[i]);
            }

            return balanced;
        }
    };
}  // namespace Leet::Medium