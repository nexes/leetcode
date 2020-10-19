#pragma once

#include <string>

namespace Leet::Easy {
    // Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
    // return the length of last word (last word means the last appearing word if we loop from
    // left to right) in the string. If the last word does not exist, return 0.

    // Note: A word is defined as a maximal substring consisting of non-space characters only.

    // Example:
    // Input: "Hello World"
    // Output: 5
    struct LengthLastWord
    {
        int lengthOfLastWord(std::string s)
        {
            auto end = s.find_last_not_of(" ");
            int count = 0;

            if (end == std::string::npos)
                return 0;

            for (int i = end; i >= 0; i--) {
                if (s[i] == ' ')
                    break;
                count++;
            }

            return count;
        }
    };
}  // namespace Leet::Easy
