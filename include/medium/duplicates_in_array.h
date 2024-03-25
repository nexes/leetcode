#pragma once

#include <cmath>
#include <vector>

namespace Leet::Medium {
    // Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
    // appear twice and others appear once. Find all the elements that appear twice
    // in this array. Could you do it without extra space and in O(n) runtime?

    // Example:
    // Input:
    // [4,3,2,7,8,2,3,1]

    // Output:
    // [2,3]
    struct DuplicatesArray
    {
        // time: O(n), using extra memory space
        std::vector<int> findDuplicates_extra_mem(std::vector<int> &nums)
        {
            std::vector<int> freq(nums.size() + 1);
            std::vector<int> out{};

            for (auto &v : nums)
                freq[v]++;

            for (int i = 0; i < freq.size(); i++)
                if (freq[i] > 1)
                    out.push_back(i);

            return out;
        }

        // time O(n), space: O(1)
        std::vector<int> findDuplicates(std::vector<int> &nums)
        {
            std::vector<int> out{};

            // treat each value in nums as an index. If we have a negative value, we've
            // been to that index before, marking it as a duplicate
            for (int i = 0; i < nums.size(); i++) {
                auto idx = std::abs(nums[i]) - 1;

                if (nums[idx] < 0)
                    out.push_back(std::abs(nums[i]));
                else
                    nums[idx] *= -1;
            }

            return out;
        }
    };
}  // namespace Leet::Medium
