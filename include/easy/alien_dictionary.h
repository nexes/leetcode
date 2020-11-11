#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace Leet::Easy {
    // In an alien language, surprisingly they also use english lowercase letters,
    // but possibly in a different order. The order of the alphabet is some permutation
    // of lowercase letters. Given a sequence of words written in the alien language,
    // and the order of the alphabet, return true if and only if the given words are
    // sorted lexicographicaly in this alien language.

    // Example 1:
    // Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
    // Output: true
    // Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

    // Example 2:
    // Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
    // Output: false
    // Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

    // Example 3:
    // Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
    // Output: false
    // Explanation: The first three characters "app" match, and the second string is shorter (in size.)
    // According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as
    // the blank character which is less than any other character (More info).

    // Constraints:
    // 1 <= words.length <= 100
    // 1 <= words[i].length <= 20
    // order.length == 26
    // All characters in words[i] and order are English lowercase letters.
    struct AlienDictionary
    {
        // time: O(n^2) space: O(1)
        bool isAlienSorted(std::vector<std::string>& words, std::string order)
        {
            bool sub_str;
            int len;
            auto char_map = std::unordered_map<char, int>(26);

            for (int i = 0; i < order.length(); i++)
                char_map[order[i]] = i + 1;

            for (int i = 0; i < words.size(); i++) {
                for (int j = i + 1; j < words.size(); j++) {
                    sub_str = true;
                    len = std::min(words[i].length(), words[j].length());

                    for (int k = 0; k < len; k++) {
                        if (words[i][k] != words[j][k])
                            sub_str = false;

                        if (char_map[words[i][k]] < char_map[words[j][k]])
                            break;

                        if (char_map[words[i][k]] > char_map[words[j][k]])
                            return false;
                    }

                    if (sub_str && words[j].length() < words[i].length())
                        return false;
                }
            }

            return true;
        }
    };
}  // namespace Leet::Easy
