#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

namespace Leet::Medium {
    // You are given a string s. We want to partition the string into as many parts as
    // possible so that each letter appears in at most one part. Note that the partition
    // is done so that after concatenating all the parts in order, the resultant string
    // should be s.

    // Return a list of integers representing the size of these parts.

    // Example 1:
    // Input: s = "ababcbacadefegdehijhklij"
    // Output: [9,7,8]
    // Explanation:
    // The partition is "ababcbaca", "defegde", "hijhklij".
    // This is a partition so that each letter appears in at most one part.
    // A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s
    // into less parts.

    // Example 2:
    // Input: s = "eccbbbbdec"
    // Output: [10]

    // Constraints:
    // 1 <= s.length <= 500
    // s consists of lowercase English letters.
    struct PartitionLabels
    {
        vector<int> partitionLabels(string s)
        {
            vector<int> groups;
            unordered_map<char, std::pair<int, int>> idx;

            for (int i = 0; i < s.length(); i++) {
                if (idx.count(s[i]) == 0)
                    idx[s[i]] = std::make_pair(i, i);
                else
                    idx[s[i]].second = i;
            }

            std::pair<int, int> current = idx[s[0]];

            for (char c : s) {
                std::pair<int, int> char_idx = idx[c];

                if (char_idx.first > current.second) {
                    groups.push_back(current.second - current.first + 1);
                    current = char_idx;
                }

                current.second = std::max(current.second, char_idx.second);
            }

            groups.push_back(current.second - current.first + 1);
            return groups;
        }
    };
}  // namespace Leet::Medium