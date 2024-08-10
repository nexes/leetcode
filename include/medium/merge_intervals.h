#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // Given an array of intervals where intervals[i] = [starti, endi], merge all
    // overlapping intervals, and return an array of the non-overlapping intervals that
    // cover all the intervals in the input.

    // Example 1:
    // Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    // Output: [[1,6],[8,10],[15,18]]
    // Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

    // Example 2:
    // Input: intervals = [[1,4],[4,5]]
    // Output: [[1,5]]
    // Explanation: Intervals [1,4] and [4,5] are considered overlapping.

    // Constraints:
    // 1 <= intervals.length <= 104
    // intervals[i].length == 2
    // 0 <= starti <= endi <= 104
    struct MergeInterval
    {
        // O(nlog(n))
        std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
        {
            std::vector<std::vector<int>> merged;

            std::sort(intervals.begin(), intervals.end());

            merged.push_back(intervals[0]);
            for (int i = 1; i < intervals.size(); i++) {
                std::vector<int> &last = merged.back();

                if (last[1] >= intervals[i][0]) {
                    last[0] = std::min(last[0], intervals[i][0]);
                    last[1] = std::max(last[1], intervals[i][1]);
                } else {
                    merged.push_back(intervals[i]);
                }
            }

            return merged;
        }
    };
}  // namespace Leet::Medium
