#pragma once

#include <vector>

namespace Leet::Medium {
    // Given an integer array nums, return an array answer such that answer[i]
    // is equal to the product of all the elements of nums except nums[i].

    // The product of any prefix or suffix of nums is guaranteed to fit in a
    // 32-bit integer.

    // You must write an algorithm that runs in O(n) time and without using the
    // division operation.

    // Example 1:
    // Input: nums = [1,2,3,4]
    // Output: [24,12,8,6]

    // Example 2:
    // Input: nums = [-1,1,0,-3,3]
    // Output: [0,0,9,0,0]

    // Constraints:
    // 2 <= nums.length <= 105
    // -30 <= nums[i] <= 30
    // The product of any prefix or suffix of nums is guaranteed to fit in a
    // 32-bit integer.

    // Follow up: Can you solve the problem in O(1) extra space complexity? (The
    // output array does not count as extra space for space complexity
    // analysis.)
    struct ProductArray
    {
        // time: O(n)
        // space: O(n)
        std::vector<int> productExceptSelf_linear(std::vector<int> &nums)
        {
            size_t size = nums.size();
            std::vector<int> products(size, 1);
            std::vector<int> leftProducts(size, 1);
            std::vector<int> rightProducts(size, 1);

            // calculate the product up to this index but not including it.
            // Starting from the left
            for (int i = 1; i < size; i++)
                leftProducts[i] = leftProducts[i - 1] * nums[i - 1];

            // calculate the product up to this index but not including it.
            // Starting from the right.
            for (int i = size - 2; i >= 0; i--)
                rightProducts[i] = rightProducts[i + 1] * nums[i + 1];

            // combine
            for (int i = 0; i < size; i++)
                products[i] = leftProducts[i] * rightProducts[i];

            return products;
        }

        // time: O(n)
        // space: O(1)
        std::vector<int> productExceptSelf(std::vector<int> &nums)
        {
            size_t size = nums.size();
            std::vector<int> answer(size, 1);

            for (int i = 1; i < size; i++) {
                answer[i] = answer[i - 1] * nums[i - 1];
            }

            int rightprod = 1;
            for (int i = size - 1; i >= 0; i--) {
                answer[i] *= rightprod;
                rightprod *= nums[i];
            }

            return answer;
        }
    };
}  // namespace Leet::Medium