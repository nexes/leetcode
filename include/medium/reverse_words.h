#pragma once

#include <string>
#include <algorithm>

#include <../common.h>

namespace Leet::Medium
{
    // Given an input string, reverse the string word by word.

    // Example 1:
    // Input: "the sky is blue"
    // Output: "blue is sky the"

    // Example 2:
    // Input: "  hello world!  "
    // Output: "world! hello"
    // Explanation: Your reversed string should not contain leading or trailing spaces.

    // Example 3:
    // Input: "a good   example"
    // Output: "example good a"
    // Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

    // Note:
    // A word is defined as a sequence of non-space characters.
    // Input string may contain leading or trailing spaces. However, your reversed string should
    // not contain leading or trailing spaces. You need to reduce multiple spaces between
    // two words to a single space in the reversed string.
    struct ReverseWords
    {
        // honestly I'm just having fun writing the common string functions found in include/common.h
        // this was more about writing the trim, split and reverse functions than solving this problem :)
        std::string reverseWords(std::string s)
        {
            std::string return_str = "";

            algo.ltrim(s);
            algo.rtrim(s);

            auto sv = algo.split(s);
            algo.reverse(sv);

            for (auto &word : sv)
            {
                if (return_str.length() > 0)
                    return_str += " ";
                return_str += word;
            }

            return return_str;
        }

    private:
        Leet::Algorithm algo;
    };
} // namespace Leet::Medium
