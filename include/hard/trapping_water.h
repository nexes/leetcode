#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Hard {
    // Given n non-negative integers representing an elevation map where the
    // width of each bar is 1, compute how much water it can trap after raining.

    // Example 1:
    // Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    // Output: 6
    // Explanation: The above elevation map (black section) is represented by
    // array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water
    // (blue section) are being trapped.

    // Example 2:
    // Input: height = [4,2,0,3,2,5]
    // Output: 9

    // Constraints:
    // n == height.length
    // 1 <= n <= 2 * 104
    // 0 <= height[i] <= 105
    struct RainWater
    {
        // time: O(n)
        // space: O(1)
        int trap(std::vector<int>& height)
        {
            int l = 0;
            int r = height.size() - 1;
            int maxleft = height[l];
            int maxright = height[r];
            int total = 0;

            while (l < r) {
                if (maxleft <= maxright) {
                    l++;
                    maxleft = std::max(maxleft, height[l]);
                    total += maxleft - height[l];
                } else {
                    r--;
                    maxright = std::max(maxright, height[r]);
                    total += maxright - height[r];
                }
            }

            return total;
        }

        // time: O(n)
        // space: O(n)
        int trap_second(std::vector<int>& height)
        {
            int total = 0;
            std::vector<int> leftmax(height.size());
            std::vector<int> rightmax(height.size());

            leftmax[0] = height[0];
            rightmax[height.size() - 1] = height[height.size() - 1];

            for (int i = 1; i < height.size(); i++)
                leftmax[i] = std::max(leftmax[i - 1], height[i]);

            for (int i = height.size() - 2; i >= 0; i--)
                rightmax[i] = std::max(rightmax[i + 1], height[i]);

            for (int i = 0; i < height.size(); i++)
                total += std::min(leftmax[i], rightmax[i]) - height[i];

            return total;
        }
    };
}  // namespace Leet::Hard
