#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

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
        vector<string> generateParentheses(int n)
        {
            vector<string> parens;
            generate(parens, "", n, n);

            return parens;
        }

        void generate(vector<string>& parens, string paren, int open, int close)
        {
            if (open == 0 && close == 0) {
                parens.push_back(paren);
                return;
            }

            // if we have an open to use
            if (open > 0) {
                generate(parens, paren + "(", open - 1, close);
            }

            // only close if we have an open (open less then the closes)
            if (open < close) {
                generate(parens, paren + ")", open, close - 1);
            }
        }
    };
}  // namespace Leet::Medium
