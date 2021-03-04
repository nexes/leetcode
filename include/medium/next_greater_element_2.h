#pragma once

#include <stack>
#include <vector>

namespace Leet::Medium {
    // Given a circular array (the next element of the last element is
    // the first element of the array), print the Next Greater Number
    // for every element. The Next Greater Number of a number x is the
    // first greater number to its traversing-order next in the array,
    // which means you could search circularly to find its next greater
    // number. If it doesn't exist, output -1 for this number.

    // Example 1:
    // Input: [1,2,1]
    // Output: [2,-1,2]

    // Explanation: The first 1's next greater number is 2;
    // The number 2 can't find next greater number;
    // The second 1's next greater number needs to search circularly, which is also 2.

    // Note: The length of given array won't exceed 10000.
    struct NextGreater2
    {
        // time: O(n^2)
        std::vector<int> nextGreaterElements(std::vector<int>& nums)
        {
            int size = nums.size();
            std::vector<int> greater(size, -1);

            for (int i = 0; i < size; i++) {
                for (int j = 1; j < size; j++) {
                    if (nums[(j + i) % size] > nums[i]) {
                        greater[i] = nums[(j + i) % size];
                        break;
                    }
                }
            }

            return greater;
        }

        // time: O(n) space: O(n)
        std::vector<int> nextGreaterElements_faster(std::vector<int>& nums)
        {
            int size = nums.size();
            std::vector<int> greater(size, -1);

            return greater;
        }
    };
}  // namespace Leet::Medium
