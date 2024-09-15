#pragma once

#include <string>
#include <vector>

namespace Leet::Medium {
    // Given the string s, return the size of the longest substring containing each vowel
    // an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even
    // number of times.

    // Example 1:
    // Input: s = "eleetminicoworoep"
    // Output: 13
    // Explanation: The longest substring is "leetminicowor" which contains two each of
    // the vowels: e, i and o and zero of the vowels: a and u.

    // Example 2:
    // Input: s = "leetcodeisgreat"
    // Output: 5
    // Explanation: The longest substring is "leetc" which contains two e's.

    // Example 3:
    // Input: s = "bcbcbc"
    // Output: 6
    // Explanation: In this case, the given string "bcbcbc" is the longest because all
    // vowels: a, e, i, o and u appear zero times.

    // Constraints:
    // 1 <= s.length <= 5 x 10^5
    // s contains only lowercase English letters.
    struct LongestSubstrEvenVowels
    {
        int findTheLongestSubstring(std::string s)
        {
            int len = 0;
            int prefix_xor = 0;
            std::vector<int> indices(32, -1);
            std::vector<int> charmap(26, 0);

            charmap['a' - 'a'] = 1;
            charmap['e' - 'a'] = 2;
            charmap['i' - 'a'] = 4;
            charmap['o' - 'a'] = 8;
            charmap['u' - 'a'] = 16;

            // we keep track of the first time we've seen this bitmask.
            // get the distance between i and the first time we've seen the
            // bitmask we're currently looking at.
            for (int i = 0; i < s.length(); i++) {
                prefix_xor ^= charmap[s[i] - 'a'];
                if (prefix_xor != 0 && indices[prefix_xor] == -1)
                    indices[prefix_xor] = i;

                len = std::max(len, i - indices[prefix_xor]);
            }

            return len;
        }
    };
}  // namespace Leet::Medium