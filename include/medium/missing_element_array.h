#pragma once

#include <vector>

namespace Leet::Medium {
    // Given a sorted array A of unique numbers, find the K-th missing number starting
    // from the leftmost number of the array.

    // Example 1:
    // Input: A = [4,7,9,10,22], K = 1 Output: 5 Explanation: The first missing number
    // is 5.

    // Example 2:
    // Input: A = [4,7,9,10], K = 3 Output: 8 Explanation: The missing numbers are
    // [5,6,8,...], hence the third missing number is 8.
    struct MissingElement
    {
        // time: O(n) space: O(1)
        int missingElement_linear(std::vector<int>& nums, int k)
        {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] - nums[0] - i >= k) {
                    return nums[i - 1] + k;
                }

                k -= nums[i] - nums[0] - i;
            }

            return 0;
        }

        // time: O(log(n)) space: O(1)
        int missingElement(std::vector<int>& nums, int k)
        {
            int check = 0;
            int low = 0;
            int mid = 0;
            int high = nums.size();

            while (low < high) {
                mid = (low + high) / 2;
                check = nums[mid] - nums[0] - mid;

                if (check < k) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }

            return low == nums.size() ? 0 : nums[low - 1] + k - check;
        }
    };
}  // namespace Leet::Medium
