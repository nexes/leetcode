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
        // clean approach, use a heap to find the next smallest value and the previous
        // smallest value.
        // O(n) n = |heights|
        int largestRectangleArea_nsv(std::vector<int> &heights)
        {
            int maxArea = 0;
            std::vector<int> nextSmallIdx(heights.size(), heights.size());
            std::vector<int> prevSmallIdx(heights.size(), -1);

            // r -> l gives us nextSmallIdx
            std::stack<int> nsHeap;
            for (int i = 0; i < heights.size(); i++) {
                while (!nsHeap.empty() && heights[nsHeap.top()] > heights[i]) {
                    nextSmallIdx[nsHeap.top()] = i;
                    nsHeap.pop();
                }
                nsHeap.push(i);
            }

            // r -> l gives us prevSmallIdx
            std::stack<int> psHeap;
            for (int i = heights.size() - 1; i >= 0; i--) {
                while (!psHeap.empty() && heights[psHeap.top()] > heights[i]) {
                    prevSmallIdx[psHeap.top()] = i;
                    psHeap.pop();
                }
                psHeap.push(i);
            }

            // calculate the area
            for (int i = 0; i < heights.size(); i++) {
                int width = std::abs(nextSmallIdx[i] - prevSmallIdx[i]) - 1;
                maxArea = std::max(maxArea, width * heights[i]);
            }

            return maxArea;
        }

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