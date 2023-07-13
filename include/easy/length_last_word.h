#pragma once

#include <string>

namespace Leet::Easy {
    // Given a string s consists of upper/lower-case alphabets and empty space
    // characters ' ', return the length of last word (last word means the last
    // appearing word if we loop from left to right) in the string. If the last
    // word does not exist, return 0.

    // Note: A word is defined as a maximal substring consisting of non-space
    // characters only.

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

        int lengthOfLastWord_cleaner(std::string s)
        {
            int len = 0;
            int idx = s.length() - 1;

            while (idx >= 0 && s[idx] == ' ')
                idx--;

            while (idx >= 0 && s[idx--] != ' ')
                len++;

            return len;
        }
    };
}  // namespace Leet::Easy
