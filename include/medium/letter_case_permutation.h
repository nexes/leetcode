#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Leet::Medium {
    // Given a string s, you can transform every letter individually to be lowercase or
    // uppercase to create another string. Return a list of all possible strings we could
    // create. Return the output in any order.

    // Example 1:
    // Input: s = "a1b2"
    // Output: ["a1b2","a1B2","A1b2","A1B2"]

    // Example 2:
    // Input: s = "3z4"
    // Output: ["3z4","3Z4"]

    // Constraints:
    // 1 <= s.length <= 12
    // s consists of lowercase English letters, uppercase English letters, and digits.
    struct LetterCasePerm
    {
        void letterCase(vector<string>& results, string s, int idx)
        {
            if (idx == s.length()) {
                results.push_back(s);
                return;
            }

            // we're not using a for loop like other permutation problems because
            // we're not moving characters around
            if (!std::isdigit(s[idx])) {
                s[idx] = std::toupper(s[idx]);
                letterCase(results, s, idx + 1);

                s[idx] = std::tolower(s[idx]);
                letterCase(results, s, idx + 1);
            } else {
                letterCase(results, s, idx + 1);
            }
        }

        vector<string> letterCasePermutation(string s)
        {
            vector<string> results;
            letterCase(results, s, 0);
            return results;
        }
    };
}  // namespace Leet::Medium