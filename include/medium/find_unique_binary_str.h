#pragma once

#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

namespace Leet::Medium {
    // Given an array of strings nums containing n unique binary strings each of length n,
    // return a binary string of length n that does not appear in nums. If there are
    // multiple answers, you may return any of them.

    // Example 1:
    // Input: nums = ["01","10"]
    // Output: "11"
    // Explanation: "11" does not appear in nums. "00" would also be correct.

    // Example 2:
    // Input: nums = ["00","01"]
    // Output: "11"
    // Explanation: "11" does not appear in nums. "10" would also be correct.

    // Example 3:
    // Input: nums = ["111","011","001"]
    // Output: "101"
    // Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would
    // also be correct.

    // Constraints:
    // n == nums.length
    // 1 <= n <= 16
    // nums[i].length == n
    // nums[i] is either '0' or '1'.
    // All the strings of nums are unique.
    struct FindUniqueBinaryStr
    {
        // brute force O(n^2)
        string findDifferentBinaryString(vector<string>& nums)
        {
            unordered_set<int> numSet;

            auto strToInt = [](string& str) -> int {
                int num = 0;
                for (int i = 0; i < str.length(); i++) {
                    num = num << 1;
                    num |= str[i] == '1' ? 1 : 0;
                }
                return num;
            };

            auto intToStr = [&nums](int i) -> string {
                string s(nums.size(), '0');
                int idx = nums.size() - 1;
                while (i > 0) {
                    if ((i & 0x01))
                        s[idx] = '1';
                    i >>= 1;
                    idx--;
                }
                return s;
            };

            for (string& num : nums)
                numSet.insert(strToInt(num));

            int maxNum = std::pow(2, (int)nums.size()) - 1;
            int foundNum = 0;
            for (int i = 0; i <= maxNum; i++) {
                if (!numSet.count(i)) {
                    foundNum = i;
                    break;
                }
            }

            return intToStr(foundNum);
        }

        // Cantor's diagonal arguments
        // As long as one character is different from each string (diagonal) it's
        // different from all
        // O(n)
        string findDifferentBinaryString_cantor(vector<string>& nums)
        {
            string ans;

            for (int i = 0; i < nums.size(); i++) {
                char curr = nums[i][i];
                ans += curr == '0' ? '1' : '0';
            }

            return ans;
        }
    };
}  // namespace Leet::Medium