#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace Leet::Medium {
    // Given two strings word1 and word2, return the minimum number of steps required to
    // make word1 and word2 the same. In one step, you can delete exactly one character in
    // either string.

    // Example 1:
    // Input: word1 = "sea", word2 = "eat"
    // Output: 2
    // Explanation: You need one step to make "sea" to "ea" and another step to make "eat"
    // to "ea".

    // Example 2:
    // Input: word1 = "leetcode", word2 = "etco"
    // Output: 4

    // Constraints:
    // 1 <= word1.length, word2.length <= 500
    // word1 and word2 consist of only lowercase English letters.
    struct DeleteTwoStrings
    {
        int minDistance(std::string word1, std::string word2)
        {
            std::vector<std::vector<int>> lcs(word1.length() + 1,
                                              std::vector<int>(word2.length() + 1, 0));

            for (int i = 1; i <= word1.length(); i++) {
                for (int j = 1; j <= word2.length(); j++) {
                    if (word1[i - 1] == word2[j - 1])
                        lcs[i][j] = lcs[i - 1][j - 1] + 1;
                    else
                        lcs[i][j] = std::max(lcs[i][j - 1], lcs[i - 1][j]);
                }
            }

            // return lcs[word1.length()][word2.length()];
            return word1.length() + word2.length() -
                   2 * lcs[word1.length()][word2.length()];
        }
    };
}  // namespace Leet::Medium
