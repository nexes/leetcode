#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // The Hamming distance between two integers is the number of positions at
    // which the corresponding bits are different. Given an integer array nums,
    // return the sum of Hamming distances between all the pairs of the integers
    // in nums.

    // Example 1:
    // Input: nums = [4,14,2]
    // Output: 6
    // Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2
    // is 0010 (just showing the four bits relevant in this case). The answer
    // will be: HammingDistance(4, 14) + HammingDistance(4, 2) +
    // HammingDistance(14, 2) = 2 + 2 + 2 = 6.

    // Example 2:
    // Input: nums = [4,14,4]
    // Output: 4

    // Constraints:
    // 1 <= nums.length <= 104
    // 0 <= nums[i] <= 109
    // The answer for the given input will fit in a 32-bit integer.
    struct TotalHamming
    {
        int totalHammingDistance(std::vector<int>& nums)
        {
            int total = 0;

            // bit position in the int
            for (int bit = 0; bit < 32; bit++) {
                int ones_count = 0;

                // count if the bit at this bit location is a one, for all
                // numbers in nums
                for (int i = 0; i < nums.size(); i++)
                    ones_count += (nums[i] >> bit) & 0x01;

                // nums.size() - ones_count = the number of elements that had a
                // zero at position 'bit'
                // ones_count = the number of elements that had a one at
                // position 'bit'
                total += ones_count * (nums.size() - ones_count);
            }

            return total;
        }

        // works but exceedes time limit: O(n^2)
        int totalHammingDistance_naive(std::vector<int>& nums)
        {
            int sum = 0;

            for (int i = 0; i < nums.size(); i++)
                for (int j = i + 1; j < nums.size(); j++)
                    sum += helper_naive(nums[i], nums[j]);

            return sum;
        }

        int helper_naive(int a, int b)
        {
            int dist = 0;

            while (a > 0 || b > 0) {
                if ((a & 0x01) != (b & 0x01))
                    dist++;
                // or dist += ((a & 1) ^ (b & 1));

                a >>= 1;
                b >>= 1;
            }

            return dist;
        }
    };
}  // namespace Leet::Medium