#pragma once

#include <stack>
#include <vector>

namespace Leet::Hard {
    // Given an array of integers heights representing the histogram's bar height where
    // the width of each bar is 1, return the area of the largest rectangle in the
    // histogram.

    // Example 1:
    // Input: heights = [2,1,5,6,2,3]
    // Output: 10
    // Explanation: The above is a histogram where width of each bar is 1.
    // The largest rectangle is shown in the red area, which has an area = 10 units.

    // Example 2:
    // Input: heights = [2,4]
    // Output: 4

    // Constraints:
    // 1 <= heights.length <= 105
    // 0 <= heights[i] <= 104
    struct LargestRectHistogram
    {
        // time: O(n)
        int largestRectangleArea(std::vector<int> &heights)
        {
            int len = heights.size();
            int maxarea = 0;
            std::stack<std::pair<int, int>> areas;

            for (int i = 0; i < heights.size(); i++) {
                int startidx = i;

                while (!areas.empty() && areas.top().first > heights[i]) {
                    std::pair<int, int> temp = areas.top();
                    areas.pop();

                    maxarea = std::max(maxarea, temp.first * (i - temp.second));
                    startidx = temp.second;
                }

                areas.push({heights[i], startidx});
            }

            while (!areas.empty()) {
                std::pair<int, int> temp = areas.top();
                areas.pop();

                maxarea = std::max(maxarea, temp.first * (len - temp.second));
            }

            return maxarea;
        }

        // time: O(n^2) TLE
        int largestRectangleArea_slow(std::vector<int> &heights)
        {
            int maxarea = heights[0];
            int minval = heights[0];

            for (int i = 0; i < heights.size(); i++) {
                minval = heights[i];
                for (int j = i; j < heights.size(); j++) {
                    minval = std::min(minval, heights[j]);
                    maxarea = std::max(maxarea, minval * ((j - i) + 1));
                }
            }

            return std::max(maxarea, minval);
        }
    };
}  // namespace Leet::Hard