#pragma once

#include <string>
#include <unordered_map>

namespace Leet::Medium {
    // Given a string s and an integer k, return the length of the longest substring of s
    // such that the frequency of each character in this substring is greater than or
    // equal to k.

    // if no such substring exists, return 0.

    // Example 1:
    // Input: s = "aaabb", k = 3
    // Output: 3
    // Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.

    // Example 2:
    // Input: s = "ababbc", k = 2
    // Output: 5
    // Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b'
    // is repeated 3 times.

    // Constraints:
    // 1 <= s.length <= 104
    // s consists of only lowercase English letters.
    // 1 <= k <= 105
    struct LongestSubstringKRepeating
    {
        int divideConquer(std::string &s, int start, int end, int k)
        {
            if (end < start)
                return 0;

            std::unordered_map<char, int> freq;
            for (int i = start; i < end; i++)
                freq[s[i]]++;

            for (int mid = start; mid < end; mid++) {
                if (freq[s[mid]] < k) {
                    return std::max(divideConquer(s, start, mid, k),
                                    divideConquer(s, mid + 1, end, k));
                }
            }

            return end - start;
        }

        int longestSubstring(std::string s, int k)
        {
            return divideConquer(s, 0, s.length(), k);
        }
    };
}  // namespace Leet::Medium