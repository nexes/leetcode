#pragma once

#include <algorithm>
#include <stack>
#include <string>
#include <vector>

namespace Leet::Medium {
    // You are given a string s consisting only of characters 'a' and
    // 'b'
    //
    // You can delete any number of characters in s to make s balanced. s is
    // balanced if there is no pair of indices (i,j) such that i < j and s[i] =
    // 'b' and s[j]= 'a'.
    //
    // Return the minimum number of deletions needed to make s balanced.
    //
    // Example 1:
    // Input: s = "aababbab"
    // Output: 2
    // Explanation: You can either:
    // Delete the characters at 0-indexed positions 2 and 6 ("aababbab" ->
    // "aaabbb"), or Delete the characters at 0-indexed positions 3 and 6
    // ("aababbab" -> "aabbbb").
    //
    // Example 2:
    // Input: s = "bbaaaaabb"
    // Output: 2
    // Explanation: The only solution is to delete the first two characters.
    //
    // Constraints:
    // 1 <= s.length <= 105
    // s[i] is 'a' or 'b'
    struct MinStringBalance
    {
        // solution using a stack
        int minimumDeletions_stack(std::string s)
        {
            int ans = 0;
            std::stack<char> stack;

            for (const char c : s) {
                if (c == 'a') {
                    if (!stack.empty()) {
                        stack.pop();
                        ans++;
                    }
                } else {
                    stack.push(c);
                }
            }

            return ans;
        }

        // prefix suffix solution
        int minimumDeletions(std::string s)
        {
            std::vector<int> prefix_a(s.length(), 0);
            std::vector<int> prefix_b(s.length(), 0);

            // how many 'b' are behind at this index
            for (int i = 1; i < s.length(); i++) {
                prefix_b[i] = prefix_b[i - 1];

                if (s[i - 1] == 'b')
                    prefix_b[i] += 1;
            }

            // how many 'a' are infront of this index
            for (int i = s.length() - 2; i >= 0; i--) {
                prefix_a[i] = prefix_a[i + 1];

                if (s[i + 1] == 'a')
                    prefix_a[i] += 1;
            }

            int ans = prefix_b[0] + prefix_a[0];

            for (int i = 0; i < s.length(); i++)
                ans = std::min(ans, prefix_b[i] + prefix_a[i]);

            return ans;
        }
    };
}  // namespace Leet::Medium
