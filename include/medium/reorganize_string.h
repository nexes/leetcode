#pragma once

#include <queue>
#include <string>
#include <vector>

using std::priority_queue;
using std::string;
using std::vector;

namespace Leet::Medium {
    // Given a string s, rearrange the characters of s so that any two adjacent characters
    // are not the same.

    // Return any possible rearrangement of s or return "" if not possible.

    // Example 1:
    // Input: s = "aab"
    // Output: "aba"

    // Example 2:
    // Input: s = "aaab"
    // Output: ""

    // Constraints:
    // 1 <= s.length <= 500
    // s consists of lowercase English letters.
    struct ReorganizeString
    {
        string reorganizeString(string s)
        {
            priority_queue<std::pair<int, char>> q;
            vector<int> charFreq(26, 0);
            string ans = "";

            for (char c : s)
                charFreq[c - 'a']++;

            for (int i = 0; i < 26; i++) {
                if (charFreq[i] > 0)
                    q.push({charFreq[i], i + 'a'});
            }

            while (!q.empty()) {
                auto [count, ch] = q.top();
                q.pop();

                if (ans.empty() || ans.back() != ch) {
                    ans.push_back(ch);

                    if (--count > 0)
                        q.push({count, ch});
                } else {
                    if (q.empty())
                        return "";

                    auto [nextCount, nextCh] = q.top();
                    q.pop();

                    ans.push_back(nextCh);
                    q.push({count, ch});

                    if (--nextCount > 0)
                        q.push({nextCount, nextCh});
                }
            }

            return ans;
        }
    };
}  // namespace Leet::Medium