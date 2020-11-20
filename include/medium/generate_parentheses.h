#pragma once

#include <string>
#include <vector>

namespace Leet::Medium {
    // Given n pairs of parentheses, write a function to generate
    // all combinations of well-formed parentheses.

    // Example 1:
    // Input: n = 3
    // Output: ["((()))","(()())","(())()","()(())","()()()"]

    // Example 2:
    // Input: n = 1
    // Output: ["()"]

    // Constraints:
    // 1 <= n <= 8
    struct GenParentheses
    {
        std::vector<std::string> generateParentheses(int n)
        {
            auto parens = std::vector<std::string>{};

            generate(parens, "", 0, 0, n);

            return parens;
        }

        void generate(std::vector<std::string>& arr, std::string curr, int open, int close, int len)
        {
            if (curr.length() == len * 2) {
                arr.push_back(curr);
                return;
            }

            if (open < len)
                generate(arr, curr + "(", open + 1, close, len);
            if (close < open)
                generate(arr, curr + ")", open, close + 1, len);
        }
    };
}  // namespace Leet::Medium
