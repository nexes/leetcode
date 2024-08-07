#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // Given n non-negative integers a1, a2, ..., an , where each represents a
    // point at coordinate (i, ai). n vertical lines are drawn such that the two
    // endpoints of line i is at (i, ai) and (i, 0). Find two lines, which
    // together with x-axis forms a container, such that the container contains
    // the most water.

    // Note: You may not slant the container and n is at least 2.

    // see https://leetcode.com/problems/container-with-most-water/

    // The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
    // this case, the max area of water (blue section) the container can contain
    // is 49.

    // Example:
    // Input: [1,8,6,2,5,4,8,3,7]
    // Output: 49
    struct Most_water
    {
        int maxArea(std::vector<int> &height)
        {
            int area = 0;
            int l = 0;
            int r = height.size() - 1;

            while (l < r) {
                int w = r - l;
                int h = std::min(height[l], height[r]);
                area = std::max(area, w * h);

                if (height[l] == height[r]) {
                    l++;
                    r--;
                } else if (height[l] < height[r]) {
                    l++;
                } else {
                    r--;
                }
            }

            return area;
        }
    };
}  // namespace Leet::Medium
