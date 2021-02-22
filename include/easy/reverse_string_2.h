#pragma once

#include <algorithm>
#include <string>

namespace Leet::Easy {
    // Given a string and an integer k, you need to reverse the first k characters for
    // every 2k characters counting from the start of the string. If there are less than k
    // characters left, reverse all of them. If there are less than 2k but greater than or
    // equal to k characters, then reverse the first k characters and left the other as
    // original.

    // Example:
    // Input: s = "abcdefg", k = 2
    // Output: "bacdfeg"

    // Restrictions: The string consists of lower English letters only. Length of the
    // given string and k will in the range [1, 10000]
    struct ReverseString2
    {
        std::string reverseStr(std::string s, int k)
        {
            int size = s.size();

            for (int i = 0; i < size; i += 2 * k) {
                int left = i;
                int right = std::min(i + k - 1, size - 1);

                while (left < right) {
                    auto temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;

                    left++;
                    right--;
                }
            }

            return s;
        }
    };
}  // namespace Leet::Easy
