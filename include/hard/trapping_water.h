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
        // this is a naive brute force solution that works but exceeded the time
        // limit
        int trap(std::vector<int>& height)
        {
            int left = 0;
            int right = 0;
            int trapped = 0;

            while (left < height.size()) {
                if (height[left] == 0) {
                    left++;
                    continue;
                }

                // this loop here is why it exceeded the time limit
                right = left + 1;
                int local_right = right;
                while (right < height.size() && height[right] < height[left]) {
                    if (height[right] > height[local_right])
                        local_right = right;

                    right++;
                }

                if (right == height.size()) {
                    if (local_right >= left + 2 &&
                        local_right < height.size()) {
                        right = local_right;
                    } else {
                        left++;
                        continue;
                    }
                }

                int l_val = std::min(height[left], height[right]);
                while (++left < right)
                    trapped += l_val - height[left];
            }

            return trapped;
        }

        int trap_fast(std::vector<int>& height)
        {
            int trapped = 0;
            int left = 0;
            int right = height.size() - 1;

            int left_max = height[left];
            int right_max = height[right];

            while (left < right) {
                left_max = std::max(left_max, height[left]);
                right_max = std::max(right_max, height[right]);

                if (height[left] < height[right])
                    trapped += left_max - height[left++];
                else
                    trapped += right_max - height[right--];
            }

            return trapped;
        }
    };
}  // namespace Leet::Hard
