#pragma once

#include <string>

namespace Leet::Easy {
    // Given a string s, reverse only all the vowels in the string and return it.
    // The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

    // Example 1:
    // Input: s = "hello"
    // Output: "holle"

    // Example 2:
    // Input: s = "leetcode"
    // Output: "leotcede"

    // Constraints:
    // 1 <= s.length <= 3 * 105
    // s consist of printable ASCII characters.
    struct ReverseVowel
    {
        bool isVowel(char c)
        {
            c = std::tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }

        std::string reverseVowels(std::string s)
        {
            int l = 0;
            int r = s.length() - 1;

            while (l < r) {
                bool l_vowel = isVowel(s[l]);
                bool r_vowel = isVowel(s[r]);

                if (l_vowel && r_vowel) {
                    char temp = s[l];
                    s[l] = s[r];
                    s[r] = temp;
                    l++;
                    r--;
                } else if (l_vowel) {
                    r--;
                } else if (r_vowel) {
                    l++;
                } else {
                    l++;
                    r--;
                }
            }

            return s;
        }
    };
}  // namespace Leet::Easy