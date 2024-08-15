#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

namespace Leet::Medium {
    // You are given a string s.
    // A split is called good if you can split s into two non-empty strings sleft and
    // sright where their concatenation is equal to s (i.e., sleft + sright = s) and the
    // number of distinct letters in sleft and sright is the same.

    // Return the number of good splits you can make in s.

    // Example 1:
    // Input: s = "aacaba"
    // Output: 2
    // Explanation: There are 5 ways to split "aacaba" and 2 of them are good.
    // ("a", "acaba") Left string and right string contains 1 and 3 different letters
    // respectively.
    // ("aa", "caba") Left string and right string contains 1 and 3 different letters
    // respectively.
    // ("aac", "aba") Left string and right string contains 2 and 2 different letters
    // respectively (good split).
    // ("aaca", "ba") Left string and right string contains 2 and 2 different letters
    // respectively (good split).
    // ("aacab", "a") Left string and right string contains 3 and 1 different letters
    // respectively.

    // Example 2:
    // Input: s = "abcd"
    // Output: 1
    // Explanation: Split the string as follows ("ab", "cd").

    // Constraints:
    // 1 <= s.length <= 105
    // s consists of only lowercase English letters.
    struct NumberGoodSplits
    {
        int numSplits(string s)
        {
            int count = 0;
            unordered_map<char, int> map1;
            unordered_map<char, int> map2;

            // O(n)
            for (char c : s)
                map1[c]++;

            // O(n)
            for (int i = 0; i < s.length() - 1; i++) {
                map2[s[i]]++;
                map1[s[i]]--;

                if (map1[s[i]] <= 0)
                    map1.erase(s[i]);  // O(1)

                if (map2.size() == map1.size())
                    count++;
            }

            return count;
        }
    };
}  // namespace Leet::Medium