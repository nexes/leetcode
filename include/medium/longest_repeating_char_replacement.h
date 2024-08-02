#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>

namespace Leet::Medium {
    // You are given a string s and an integer k. You can choose any character of the
    // string and change it to any other uppercase English character. You can perform this
    // operation at most k times. Return the length of the longest substring containing
    // the same letter you can get after performing the above operations.

    // Example 1:
    // Input: s = "ABAB", k = 2
    // Output: 4
    // Explanation: Replace the two 'A's with two 'B's or vice versa.

    // Example 2:
    // Input: s = "AABABBA", k = 1
    // Output: 4
    // Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    // The substring "BBBB" has the longest repeating letters, which is 4.
    // There may exists other ways to achieve this answer too.

    // Constraints:
    // 1 <= s.length <= 105
    // s consists of only uppercase English letters.
    // 0 <= k <= s.length
    struct LongestRepeatingReplace
    {
        int characterReplacement(std::string s, int k)
        {
            int l = 0;
            int r = 0;
            std::unordered_map<char, int> window_freq;

            int maxfreq = 0;
            while (r < s.length()) {
                window_freq[s[r]]++;
                maxfreq = std::max(maxfreq, window_freq[s[r]]);

                if ((r - l + 1) - maxfreq > k) {
                    window_freq[s[l]]--;
                    l++;
                }

                r++;
            }

            return r - l;
        }
    };
}  // namespace Leet::Medium