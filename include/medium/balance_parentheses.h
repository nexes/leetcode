#pragma once

#include <stack>
#include <string>

namespace Leet::Medium {
    // Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:
    // Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
    // Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
    // In other words, we treat '(' as openning parenthesis and '))' as closing parenthesis.

    // For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
    // You can insert the characters '(' and ')' at any position of the string to balance it if needed.
    // Return the minimum number of insertions needed to make s balanced.

    // Input: s = "(()))"
    // Output: 1
    // Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need to to add one more ')' at the end of the string to be "(())))" which is balanced.

    // Example 2:
    // Input: s = "())"
    // Output: 0
    // Explanation: The string is already balanced.

    // Example 3:
    // Input: s = "))())("
    // Output: 3
    // Explanation: Add '(' to match the first '))', Add '))' to match the last '('.

    // Example 4:
    // Input: s = "(((((("
    // Output: 12
    // Explanation: Add 12 ')' to balance the string.

    // Example 5:
    // Input: s = ")))))))"
    // Output: 5
    // Explanation: Add 4 '(' at the beginning of the string and one ')' at the end. The string becomes "(((())))))))".

    // Constraints:
    // 1 <= s.length <= 10^5
    // s consists of '(' and ')' only.
    struct BalancedParens
    {
        int minInsertions(std::string s)
        {
            std::stack<char> stack{};
            int len = s.length();
            int err = 0;

            for (int i = 0; i < len; i++)
            {
                if (s[i] == '(')
                {
                    // (
                    stack.push('(');
                    continue;
                }

                if (i + 1 < len)
                {
                    if (s[i + 1] == ')')
                    {
                        // ))
                        if (stack.size() > 0)
                            stack.pop();
                        else
                            err++;
                    } else
                    {
                        // )(
                        if (stack.size() > 0)
                        {
                            err++;
                            stack.pop();
                        } else
                        {
                            err += 2;
                        }

                        stack.push('(');
                    }

                    i++;

                } else
                {
                    // ) at the end
                    if (stack.size() > 0)
                    {
                        stack.pop();
                        err++;

                    } else
                    {
                        err += 2;
                    }
                }
            }

            err += stack.size() * 2;
            return err;
        }
    };
}  // namespace Leet::Medium
