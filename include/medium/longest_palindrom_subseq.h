#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Leet::Medium {
    // Given a string s, find the longest palindromic subsequence's length in s.
    // A subsequence is a sequence that can be derived from another sequence by deleting
    // some or no elements without changing the order of the remaining elements.

    // Example 1:
    // Input: s = "bbbab"
    // Output: 4
    // Explanation: One possible longest palindromic subsequence is "bbbb".

    // Example 2:
    // Input: s = "cbbd"
    // Output: 2
    // Explanation: One possible longest palindromic subsequence is "bb".

    // Constraints:
    // 1 <= s.length <= 1000
    // s consists only of lowercase English letters.
    struct LongestPalindromSubSeq
    {
        int longestPalindromeSubseq(string s)
        {
            int len = s.size();
            vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));

            // O(n)
            string rs = s;
            std::reverse(rs.begin(), rs.end());

            // O(n^2)
            for (int i = 1; i <= len; i++) {
                for (int j = 1; j <= len; j++) {
                    if (s[i - 1] == rs[j - 1])
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }

            return dp[len][len];
        }
    };
}  // namespace Leet::Medium