#pragma once

#include <vector>

namespace Leet::Medium {
    // Given an integer array nums, find a
    // subarray that has the largest product, and return the product.

    // The test cases are generated so that the answer will fit in a 32-bit integer.

    // Example 1:
    // Input: nums = [2,3,-2,4]
    // Output: 6
    // Explanation: [2,3] has the largest product 6.

    // Example 2:
    // Input: nums = [-2,0,-1]
    // Output: 0
    // Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

    // Constraints:
    // 1 <= nums.length <= 2 * 104
    // -10 <= nums[i] <= 10
    // The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
    struct MaxProduct
    {
        // time: O(n^2)
        int maxProduct_bruteforce(std::vector<int>& nums)
        {
            int maxProd = nums[0];

            for (int i = 0; i < nums.size(); i++) {
                int localProd = nums[i];
                maxProd = std::max(maxProd, localProd);

                for (int j = i + 1; j < nums.size(); j++) {
                    localProd *= nums[j];
                    maxProd = std::max(maxProd, localProd);
                }
            }

            return maxProd;
        }

        // time: O(n)
        // we need to travel from left to right and right to left. If we encounter a
        // negative number, it could make the rest of the product negative from that point
        // on. So we traverse the other direction too, to see if the product of the suffix
        // is larger
        int maxProduct(std::vector<int>& nums)
        {
            int prefixMax = INT_MIN;
            int suffixMax = INT_MIN;

            int localPrefix = 1;
            for (int i = 0; i < nums.size(); i++) {
                localPrefix *= nums[i];
                prefixMax = std::max(prefixMax, localPrefix);

                // if we find a 0, we need to restart our subarry (set to 1) otherwise the
                // rest of the array will be 0
                if (nums[i] == 0) {
                    localPrefix = 1;
                }
            }

            int localSuffix = 1;
            for (int i = nums.size() - 1; i >= 0; i--) {
                localSuffix *= nums[i];
                prefixMax = std::max(prefixMax, localSuffix);

                // if we find a 0, we need to restart our subarry (set to 1) otherwise the
                // rest of the array will be 0
                if (nums[i] == 0) {
                    localSuffix = 1;
                }
            }

            return std::max(prefixMax, suffixMax);
        }
    };
}  // namespace Leet::Medium
