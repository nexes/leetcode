#pragma once

#include <string>

namespace Leet::Easy {
    // Given two strings s and goal, return true if and only if s can become
    // goal after some number of shifts on s. A shift on s consists of moving
    // the leftmost character of s to the rightmost position. For example, if s
    // = "abcde", then it will be "bcdea" after one shift.

    // Example 1:
    // Input: s = "abcde", goal = "cdeab"
    // Output: true

    // Example 2:
    // Input: s = "abcde", goal = "abced"
    // Output: false

    // Constraints:
    // 1 <= s.length, goal.length <= 100
    // s and goal consist of lowercase English letters.
    struct RotateString
    {
        // concat the string s to itself, and see if goal can be found
        // this works but I feel is 'cheating' a little bit
        bool rotateString_append(std::string s, std::string goal)
        {
            if (s.length() != goal.length())
                return false;

            std::string ss = s.append(s);
            return ss.find(goal) != std::string::npos;
        }

        // solves the problem without using the string's 'find' method
        bool rotateString(std::string s, std::string goal)
        {
            int len = s.length();

            if (len != goal.length())
                return false;

            for (int i = 0; i < len; i++) {
                if (s[i] == goal[0]) {
                    int idx;

                    for (idx = 0; idx < len; idx++) {
                        if (s[(idx + i) % len] != goal[idx])
                            break;
                    }

                    if (idx == len)
                        return true;
                }
            }

            return false;
        }
    };
}  // namespace Leet::Easy