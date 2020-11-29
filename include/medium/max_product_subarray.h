#pragma once

#include <algorithm>
#include <climits>
#include <vector>

namespace Leet::Medium {
    // Given an integer array nums, find the contiguous subarray within an
    // array (containing at least one number) which has the largest product.

    // Example 1:
    // Input: [2,3,-2,4]
    // Output: 6
    // Explanation: [2,3] has the largest product 6.

    // Example 2:
    // Input: [-2,0,-1]
    // Output: 0
    // Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
    struct MaxProduct
    {
        int maxProduct(std::vector<int>& nums)
        {
            auto map = std::vector<std::vector<int>>(nums.size(), std::vector<int>(nums.size()));
            int len = nums.size();
            int max_prod = INT_MIN;

            // set diagonal
            for (int i = 0; i < len; i++)
                map[i][i] = nums[i];

            // dp: O(n^2)
            for (int i = 0; i < len; i++) {
                for (int j = i + 1; j < len; j++) {
                    map[i][j] = map[i][j - 1] * nums[j];
                    max_prod = std::max(max_prod, map[i][j]);
                }

                max_prod = std::max(max_prod, nums[i]);
            }

            return max_prod;
        }

        int maxProduct_linear(std::vector<int>& nums)
        {
            if (nums.size() == 1)
                return nums[0];

            int max_prod = nums[0];
            int max_here = nums[0];
            int min_here = nums[0];

            for (int i = 1; i < nums.size(); i++) {
                int temp = max_here;
                max_here = std::max(max_here * nums[i], std::max(nums[i], min_here * nums[i]));
                min_here = std::min(min_here * nums[i], std::min(nums[i], temp * nums[i]));
                max_prod = std::max(max_prod, max_here);
            }

            return max_prod;
        }
    };
}  // namespace Leet::Medium
