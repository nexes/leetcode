#pragma once

#include <string>
#include <vector>

namespace Leet::Medium {
    // Given a string s, remove duplicate letters so that every letter appears once and
    // only once. You must make sure your result is the smallest in lexicographical order
    // among all possible results.

    // Example 1:
    // Input: s = "bcabc"
    // Output: "abc"

    // Example 2:
    // Input: s = "cbacdcbc"
    // Output: "acdb"

    // Constraints:
    // 1 <= s.length <= 104
    // s consists of lowercase English letters.
    struct RemoveDuplicate
    {
        std::string removeDuplicateLetters(std::string s)
        {
            std::vector<bool> seen(26);
            std::vector<int> freq(26);
            std::string no_dups{""};

            for (const auto& c : s)
                freq[c - 'a']++;

            for (const auto& c : s) {
                freq[c - 'a']--;

                if (!seen[c - 'a']) {
                    while (!no_dups.empty() && c < no_dups.back() && freq[no_dups.back() - 'a'] > 0) {
                        seen[no_dups.back() - 'a'] = false;
                        no_dups.pop_back();
                    }
                    no_dups.push_back(c);
                    seen[c - 'a'] = true;
                }
            }

            return no_dups;
        }
    };
}  // namespace Leet::Medium
