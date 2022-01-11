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
        std::vector<int> productExceptSelf(std::vector<int> &nums)
        {
            std::vector<int> products(nums.size(), 0);
            int totalProduct = nums[0];
            int zeroIndex = 0;
            bool foundZero = nums[0] == 0 ? true : false;

            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    // multiple zeros
                    if (foundZero)
                        return products;

                    foundZero = true;
                    zeroIndex = i;
                } else {
                    totalProduct *= nums[i];
                }
            }

            if (foundZero) {
                products[zeroIndex] = totalProduct;

            } else {
                for (int i = 0; i < products.size(); i++)
                    products[i] = totalProduct / nums[i];
            }

            return products;
        }

        std::vector<int> productExceptSelf_noDivision(std::vector<int> &nums)
        {
            int size = nums.size();
            std::vector<int> products(size, 0);
            std::vector<int> leftProducts(size);
            std::vector<int> rightProducts(size);

            leftProducts[0] = 1;
            rightProducts[size - 1] = 1;

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
    };
}  // namespace Leet::Medium