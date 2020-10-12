#pragma once

#include <cmath>
#include <vector>

namespace Leet::Easy {
    // Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear
    // twice and others appear once.
    //
    // Find all the elements of [1, n] inclusive that do not
    // appear in this array. Could you do it without extra space and in O(n) runtime?
    // You may assume the returned list does not count as extra space.

    // Example:
    // Input:
    // [4,3,2,7,8,2,3,1]

    // Output:
    // [5,6]
    struct DisappearNums
    {
        std::vector<int> findDisappearedNumbers_more_memory(std::vector<int> &nums)
        {
            std::vector<int> missing(nums.size());
            std::vector<int> out{};

            for (auto &v : nums)
                missing[v - 1]++;

            for (int i = 0; i < nums.size(); i++)
                if (missing[i] == 0)
                    out.push_back(i + 1);

            return out;
        }

        // without extra memory
        std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
        {
            std::vector<int> missing{};

            for (int i = 0; i < nums.size(); i++)
            {
                auto idx = std::abs(nums[i]) - 1;
                if (nums[idx] > 0)
                    nums[idx] *= -1;
            }

            for (int i = 0; i < nums.size(); i++)
                if (nums[i] > 0)
                    missing.push_back(i + 1);

            return missing;
        }
    };
}  // namespace Leet::Easy
