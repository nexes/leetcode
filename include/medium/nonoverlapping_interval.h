#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // Given a collection of intervals, find the minimum number of intervals you
    // need to remove to make the rest of the intervals non-overlapping.

    // Example 1:
    // Input: [[1,2],[2,3],[3,4],[1,3]]
    // Output: 1
    // Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.

    // Example 2:
    // Input: [[1,2],[1,2],[1,2]]
    // Output: 2
    // Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.

    // Example 3:
    // Input: [[1,2],[2,3]]
    // Output: 0
    // Explanation: You don't need to remove any of the intervals since they're already
    // non-overlapping.

    // Note:
    // You may assume the interval's end point is always bigger than its start point.
    // Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
    struct NonOverlapInterval
    {
        int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
        {
            int removed = 0;

            if (intervals.empty())
                return 0;

            std::sort(
                intervals.begin(),
                intervals.end(),
                [](const std::vector<int>& v1, const std::vector<int>& v2) {
                    return v1[1] < v2[1];
                });

            auto curr = intervals[0];

            // after sorting by endpoint
            // [[1,11],[2,12],[11,22],[1,100]]
            for (int i = 1; i < intervals.size(); i++) {
                if (intervals[i][0] >= curr[1])
                    curr = intervals[i];
                else
                    removed++;
            }

            return removed;
        }
    };
}  // namespace Leet::Medium
