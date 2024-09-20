#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Leet::Medium {
    // Given a string expression of numbers and operators, return all possible results
    // from computing all the different possible ways to group numbers and operators. You
    // may return the answer in any order.

    // The test cases are generated such that the output values fit in a 32-bit integer
    // and the number of different results does not exceed 104.

    // Example 1:
    // Input: expression = "2-1-1"
    // Output: [0,2]
    // Explanation:
    // ((2-1)-1) = 0
    // (2-(1-1)) = 2

    // Example 2:
    // Input: expression = "2*3-4*5"
    // Output: [-34,-14,-10,-10,10]
    // Explanation:
    // (2*(3-(4*5))) = -34
    // ((2*3)-(4*5)) = -14
    // ((2*(3-4))*5) = -10
    // (2*((3-4)*5)) = -10
    // (((2*3)-4)*5) = 10

    // Constraints:
    // 1 <= expression.length <= 20
    // expression consists of digits and the operator '+', '-', and '*'.
    // All the integer values in the input expression are in the range [0, 99].
    // The integer values in the input expression do not have a leading '-' or '+'
    // denoting the sign.
    struct DiffWaysToAddParens
    {
        vector<int> diffWaysToCompute(string expr)
        {
            vector<int> res;

            for (int i = 0; i < expr.length(); i++) {
                char op = expr[i];

                if (op == '-' || op == '+' || op == '*') {
                    vector<int> left = diffWaysToCompute(expr.substr(0, i));
                    vector<int> right = diffWaysToCompute(expr.substr(i + 1));

                    for (int li : left) {
                        for (int ri : right) {
                            if (op == '-')
                                res.push_back(li - ri);
                            if (op == '+')
                                res.push_back(li + ri);
                            if (op == '*')
                                res.push_back(li * ri);
                        }
                    }
                }
            }

            if (res.empty())
                res.push_back(std::stoi(expr));

            return res;
        }
    };
}  // namespace Leet::Medium