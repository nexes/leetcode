#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
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
        // O(n * k) n = |strs|  k = |strs_i|
        vector<vector<string>> groupAnagrams_faster(vector<string>& strs)
        {
            vector<vector<string>> anagrams;
            unordered_map<string, vector<string>> anagMap;

            // create a simple hash of the string that doesn't take into count the
            // position of the char
            for (string str : strs) {
                string key(26, '*');
                for (int i = 0; i < str.length(); i++)
                    key[str[i] - 'a']++;

                anagMap[key].push_back(str);
            }

            for (auto [_, value] : anagMap)
                anagrams.push_back(value);

            return anagrams;
        }

        vector<vector<string>> groupAnagrams(vector<string>& strs)
        {
            unordered_map<string, vector<string>> group_map;
            vector<vector<string>> groups;

            // O(n * mlog(m))
            int i = 0;
            for (string str : strs) {
                std::sort(str.begin(), str.end());
                group_map[str].push_back(strs[i++]);
            }

            // O(k)
            for (auto value : group_map)
                groups.push_back(value.second);

            return groups;
        }
    };
}  // namespace Leet::Medium
