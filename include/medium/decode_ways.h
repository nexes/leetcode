#pragma once

#include <string>
#include <vector>

namespace Leet::Medium {
    // You have intercepted a secret message encoded as a string of numbers. The message
    // is decoded via the following mapping:

    // "1" -> 'A'
    // "2" -> 'B'
    // ...
    // "25" -> 'Y'
    // "26" -> 'Z'

    // However, while decoding the message, you realize that there are many different ways
    // you can decode the message because some codes are contained in other codes ("2" and
    // "5" vs "25").

    // For example, "11106" can be decoded into:

    // "AAJF" with the grouping (1, 1, 10, 6)
    // "KJF" with the grouping (11, 10, 6)
    // The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is
    // valid). Note: there may be strings that are impossible to decode.

    // Given a string s containing only digits, return the number of ways to decode it. If
    // the entire string cannot be decoded in any valid way, return 0.

    // The test cases are generated so that the answer fits in a 32-bit integer.

    // Example 1:
    // Input: s = "12"
    // Output: 2
    // Explanation:
    // "12" could be decoded as "AB" (1 2) or "L" (12).

    // Example 2:
    // Input: s = "226"
    // Output: 3
    // Explanation:
    // "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

    // Example 3:
    // Input: s = "06"
    // Output: 0
    // Explanation:
    // "06" cannot be mapped to "F" because of the leading zero ("6" is different from
    // "06"). In this case, the string is not a valid encoding, so return 0.

    // Constraints:
    // 1 <= s.length <= 100
    // s contains only digits and may contain leading zero(s).
    struct DecodeWays
    {
        // ----------------- TOP DOWN DP --------------------------------
        int decode_topdown(std::string s, std::vector<int>& memo, int idx)
        {
            if (s[idx] == '0')
                return 0;
            if (idx == s.length())
                return 1;

            if (memo[idx] != -1)
                return memo[idx];

            int count = decode_topdown(s, memo, idx + 1);

            if (idx + 2 <= s.length()) {
                int twoDigit = std::stoi(s.substr(idx, 2));
                if (twoDigit <= 26)
                    count += decode_topdown(s, memo, idx + 2);
            }

            memo[idx] = count;
            return memo[idx];
        }

        int numDecodings_topdown(std::string s)
        {
            std::vector<int> memo(s.length(), -1);
            return decode_topdown(s, memo, 0);
        }

        // ----------------- BOTTOM UP DP --------------------------------
        int numDecodings(std::string s)
        {
            std::vector<int> memo(s.length() + 1, 0);
            memo[0] = 1;
            memo[1] = s[0] == '0' ? 0 : 1;

            for (int i = 2; i <= s.length(); i++) {
                if (s[i - 1] != '0')
                    memo[i] = memo[i - 1];

                int twoDigit = std::stoi(s.substr(i - 2, 2));
                if (twoDigit > 9 && twoDigit < 27)
                    memo[i] += memo[i - 2];
            }

            return memo[s.length()];
        }
    };
}  // namespace Leet::Medium