#pragma once

#include <vector>
#include <iostream>

namespace Leet::Medium
{
    // Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous
    // subarray of which the sum ≥ s. If there isn't one, return 0 instead.

    // Example:
    // Input: s = 7, nums = [2,3,1,2,4,3]
    // Output: 2

    // Explanation: the subarray [4,3] has the minimal length under the problem constraint.

    // Follow up:
    // If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
    struct MinSubArray
    {
        // O(n^2)
        int minSubArrayLen(int s, std::vector<int> &nums)
        {
            int size = nums.size();
            int length = size + 1;
            int sum = 0;

            for (int i = 0; i < size; i++)
            {
                sum = 0;

                for (int j = i; j < size; j++)
                {
                    sum += nums[j];

                    if (sum >= s)
                    {
                        length = std::min(length, j - i + 1);
                        j = size; // just need to break the inner loop
                    }
                }
            }

            return length == size + 1 ? 0 : length;
        }

        // O(n)
        // we keep adding numbers until we have a subarray ge to s. Then we start removing from the left
        // as much as we can while still being ge to s.
        int minSubArrayLen_faster(int s, std::vector<int> &nums)
        {
            int size = nums.size();
            int length = size + 1;
            int sum = 0;
            int j = 0;

            for (int i = 0; i < size; i++)
            {
                sum += nums[i];

                while (sum >= s && j <= i)
                {
                    length = std::min(length, i - j + 1);
                    sum -= nums[j++];
                }
            }

            return length == size + 1 ? 0 : length;
        }
    };
} // namespace Leet::Medium
