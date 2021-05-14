#pragma once

#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Leet::Medium {
    // Given an array of strings strs, group the anagrams together. You can return the
    // answer in any order.
    // An Anagram is a word or phrase formed by rearranging the letters of a different
    // word or phrase, typically using all the original letters exactly once.

    // Example 1:
    // Input: strs = ["eat","tea","tan","ate","nat","bat"]
    // Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    // Example 2:
    // Input: strs = [""]
    // Output: [[""]]

    // Example 3:
    // Input: strs = ["a"]
    // Output: [["a"]]

    // Constraints:
    //  1 <= strs.length <= 104
    //  0 <= strs[i].length <= 100
    //  strs[i] consists of lower-case English letters.
    struct GroupAnagram
    {
        vector<vector<string>> groupAnagrams(vector<string>& strs)
        {
            vector<string> sorted_strs{};
            vector<vector<string>> out{};

            if (strs.size() < 2) {
                out.emplace_back(strs);
                return out;
            }

            // O(n * mlog(m))
            for (auto word : strs) {
                std::sort(word.begin(), word.end());
                sorted_strs.emplace_back(word);
            }

            // O(n ^2)
            for (int i = 0; i < strs.size(); i++) {
                if (sorted_strs[i] == "*")
                    continue;

                auto temp = vector<string>{};
                temp.push_back(strs[i]);

                for (int j = i + 1; j < strs.size(); j++) {
                    if (sorted_strs[i] == sorted_strs[j]) {
                        temp.emplace_back(strs[j]);
                        sorted_strs[j] = "*";
                    }
                }

                out.emplace_back(temp);
            }

            return out;
        }
    };
}  // namespace Leet::Medium
