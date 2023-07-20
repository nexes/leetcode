#pragma once

#include <cctype>
#include <string>

namespace Leet::Easy {
    // Given a string, determine if it is a palindrome, considering only
    // alphanumeric characters and ignoring cases. Note: For the purpose of this
    // problem, we define empty string as valid palindrome.

    // Example 1:
    // Input: "A man, a plan, a canal: Panama"
    // Output: true

    // Example 2:
    // Input: "race a car"
    // Output: false

    // Constraints:
    // s consists only of printable ASCII characters.
    struct ValidPalindrome
    {
        bool isPalindrome_cleaner(std::string s)
        {
            int left = 0;
            int right = s.length() - 1;

            while (left < right) {
                if (!std::isalnum(s[left])) {
                    left++;
                    continue;
                }

                if (!std::isalnum(s[right])) {
                    right--;
                    continue;
                }

                if (std::tolower(s[left]) != std::tolower(s[right]))
                    return false;

                left++;
                right--;
            }

            return true;
        }

        bool isPalindrome(std::string s)
        {
            int left = 0;
            int right = s.length() - 1;

            while (left < right) {
                char l_char = std::tolower(s[left]);
                char r_char = std::tolower(s[right]);

                if (std::isalnum(l_char) && std::isalnum(r_char)) {
                    if (l_char != r_char)
                        return false;

                    left++;
                    right--;
                }

                if (!std::isalnum(l_char))
                    left++;

                if (!std::isalnum(r_char))
                    right--;
            }

            return true;
        }
    };
}  // namespace Leet::Easy
