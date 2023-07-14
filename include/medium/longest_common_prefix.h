#pragma once

#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Leet::Medium {
    // Write a function to find the longest common prefix string amongst an
    // array of strings. If there is no common prefix, return an empty string
    // "".

    // Example 1:
    // Input: strs = ["flower","flow","flight"]
    // Output: "fl"

    // Example 2:
    // Input: strs = ["dog","racecar","car"]
    // Output: ""
    // Explanation: There is no common prefix among the input strings.

    // Constraints:
    // 1 <= strs.length <= 200
    // 0 <= strs[i].length <= 200
    // strs[i] consists of only lowercase English letters.
    struct LongestPrefix
    {
        string longestCommonPrefix(vector<string> &strs)
        {
            string prefix = "";

            // sort the words in lexigraphical order
            // if the words are sorted in this way, we just need to check to
            // first and last string to find the LCP because these two strings
            // will be the most different. So what is common between these two,
            // will be common in all others
            std::sort(strs.begin(), strs.end());

            string first = strs[0];
            string last = strs[strs.size() - 1];
            int len = std::min(first.length(), last.length());

            for (int i = 0; i < len; i++) {
                if (first[i] == last[i])
                    prefix += first[i];
                else
                    break;
            }

            return prefix;
        }
    };
}  // namespace Leet::Medium
