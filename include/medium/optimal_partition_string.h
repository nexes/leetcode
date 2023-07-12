#pragma once

#include <string>
#include <vector>

namespace Leet::Medium {
    // Given a string s, partition the string into one or more substrings such
    // that the characters in each substring are unique. That is, no letter
    // appears in a single substring more than once. Return the minimum number
    // of substrings in such a partition. Note that each character should belong
    // to exactly one substring in a partition.

    // Example 1:
    // Input: s = "abacaba"
    // Output: 4
    // Explanation:
    // Two possible partitions are ("a","ba","cab","a") and
    // ("ab","a","ca","ba"). It can be shown that 4 is the minimum number of
    // substrings needed.

    // Example 2:
    // Input: s = "ssssss"
    // Output: 6
    // Explanation:
    // The only valid partition is ("s","s","s","s","s","s").

    // Constraints:
    // 1 <= s.length <= 105
    // s consists of only English lowercase letters.
    struct PartitionString
    {
        int partitionString(std::string s)
        {
            int count = 1;
            std::vector<int> seen(26, -1);

            // count will keep track of which substring the current char is in.
            // once we see a duplicate, char == count we increment count (start
            // a new substring) and keep going
            for (int i = 0; i < s.length(); i++) {
                if (seen[s[i] - 'a'] == count)
                    count++;

                seen[s[i] - 'a'] = count;
            }

            return count;
        }
    };
}  // namespace Leet::Medium