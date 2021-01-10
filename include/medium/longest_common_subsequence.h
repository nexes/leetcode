#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace Leet::Medium {
    // Given two strings text1 and text2, return the length of their longest common
    // subsequence.

    // A subsequence of a string is a new string generated from the original string with
    // some characters(can be none) deleted without changing the relative order of the
    // remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A
    // common subsequence of two strings is a subsequence that is common to both strings.

    // If there is no common subsequence, return 0.

    // Example 1:
    // Input: text1 = "abcde", text2 = "ace"
    // Output: 3
    // Explanation: The longest common subsequence is "ace" and its length is 3.

    // Example 2:
    // Input: text1 = "abc", text2 = "abc"
    // Output: 3
    // Explanation: The longest common subsequence is "abc" and its length is 3.

    // Example 3:
    // Input: text1 = "abc", text2 = "def"
    // Output: 0
    // Explanation: There is no such common subsequence, so the result is 0.

    // Constraints:
    //     1 <= text1.length <= 1000
    //     1 <= text2.length <= 1000
    //     The input strings consist of lowercase English characters only.
    struct LCS
    {
        int longestCommonSubsequence(std::string text1, std::string text2)
        {
            std::vector<std::vector<int>> dp(text1.length() + 1,
                                             std::vector<int>(text2.length() + 1, 0));

            for (int i = 1; i <= text1.length(); i++) {
                for (int j = 1; j <= text2.length(); j++) {
                    if (text1[i - 1] == text2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                    }
                }
            }

            return dp[text1.length()][text2.length()];
        }
    };
}  // namespace Leet::Medium
