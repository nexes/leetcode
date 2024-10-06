#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Leet::Medium {
    // Given a string s, partition s such that every
    // substring  of the partition is a palindrome. Return all possible palindrome
    // partitioning of s.

    // Example 1:
    // Input: s = "aab"
    // Output: [["a","a","b"],["aa","b"]]

    // Example 2:
    // Input: s = "a"
    // Output: [["a"]]

    // Constraints:
    // 1 <= s.length <= 16
    // s contains only lowercase English letters.
    struct PalindromeParition
    {
        bool isPalindrome(string s, int l, int r)
        {
            while (l < r && s[l] == s[r]) {
                l++;
                r--;
            }
            return l >= r;
        }

        void findPalindrome(vector<vector<string>>& pal, vector<string>& curr, string s,
                            int idx)
        {
            if (idx == s.length()) {
                pal.push_back(curr);
                return;
            }

            for (int i = idx; i < s.length(); i++) {
                if (isPalindrome(s, idx, i)) {
                    curr.push_back(s.substr(idx, i - idx + 1));
                    findPalindrome(pal, curr, s, i + 1);
                    curr.pop_back();
                }
            }
        }

        vector<vector<string>> partition(string s)
        {
            vector<vector<string>> pal;
            vector<string> curr;

            findPalindrome(pal, curr, s, 0);
            return pal;
        }
    };
}  // namespace Leet::Medium