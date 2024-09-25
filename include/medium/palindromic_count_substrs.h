#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Leet::Medium {
    // Given a string s, return the number of palindromic substrings in it.
    // A string is a palindrome when it reads the same backward as forward.

    // A substring is a contiguous sequence of characters within the string.

    // Example 1:
    // Input: s = "abc"
    // Output: 3
    // Explanation: Three palindromic strings: "a", "b", "c".

    // Example 2:
    // Input: s = "aaa"
    // Output: 6
    // Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

    // Constraints:
    // 1 <= s.length <= 1000
    // s consists of lowercase English letters.
    struct PalindromicCountSubstr
    {
        // time: O(n^2)
        int countSubstrings(string s)
        {
            int count = 0;

            auto check = [&s](int l, int r) -> int {
                int c = 0;
                // each time s[l] == s[r] that is a palindrom substring
                while (l >= 0 && r < s.length() && s[l--] == s[r++])
                    c++;

                return c;
            };

            // start from each character and move out from the middle.
            for (int i = 0; i < s.length(); i++) {
                int even = check(i, i);
                int odd = check(i, i + 1);

                count += even + odd;
            }

            return count;
        }

        // time: O(n^3)
        int countSubstrings_brute_force(string s)
        {
            int count = 0;
            for (int i = 0; i < s.length(); i++) {
                for (int j = i; j < s.length(); j++) {
                    if (s[i] == s[j]) {
                        int left = i;
                        int right = j;
                        bool anagram = true;

                        while (left < right) {
                            if (s[left++] != s[right--]) {
                                anagram = false;
                                break;
                            }
                        }
                        if (anagram)
                            count++;
                    }
                }
            }

            return count;
        }
    };
}  // namespace Leet::Medium