#pragma once

#include <stack>
#include <vector>

using std::stack;
using std::vector;

namespace Leet::Medium {
    // Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <=
    // A[j]. The width of such a ramp is j - i. Find the maximum width of a ramp in A. If
    // one doesn't exist, return 0.

    // Example 1:
    // Input: [6,0,8,2,1,5]
    // Output: 4
    // Explanation:
    // The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.

    // Example 2:
    // Input: [9,8,1,0,1,9,4,0,4,1]
    // Output: 7
    // Explanation:
    // The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.

    // Note:
    // 2 <= A.length <= 50000
    // 0 <= A[i] <= 50000
    struct MaxWidthRamp
    {
        int maxWidthRamp(vector<int>& nums)
        {
            int width = 0;
            stack<int> indices;

            // save the smallest values, so we can check them later, mono dec stack
            for (int i = 0; i < nums.size(); i++) {
                if (indices.empty() || nums[indices.top()] > nums[i])
                    indices.push(i);
            }

            // starting from the right (gives us the greatest widths) check the stack
            for (int i = nums.size() - 1; i >= 0; i--) {
                while (!indices.empty() && nums[i] >= nums[indices.top()]) {
                    int j = indices.top();
                    indices.pop();

                    width = std::max(width, i - j);
                }
            }

            return width;
        }
    };
}  // namespace Leet::Medium
