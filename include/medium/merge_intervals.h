#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // Given a collection of intervals, merge all overlapping intervals.

    // Example 1:
    // Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    // Output: [[1,6],[8,10],[15,18]]
    // Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

    // Example 2:
    // Input: intervals = [[1,4],[4,5]]
    // Output: [[1,5]]
    // Explanation: Intervals [1,4] and [4,5] are considered overlapping.

    // NOTE: input types have been changed on April 15, 2019. Please reset to default
    // code definition to get new method signature.

    // Constraints:
    // intervals[i][0] <= intervals[i][1]
    struct MergeInterval
    {
        // O(nlog(n))
        std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
        {
            std::vector<std::vector<int>> out{};
            int len = intervals.size();

            if (len == 0) return out;

            // O(nlog(n))
            // sort our input by smallest first number than by largest second number
            // e.g [(0,2), (0,1), (1,9), ...]
            std::sort(intervals.begin(), intervals.end(),
                      [&intervals](const std::vector<int> &t1, const std::vector<int> &t2) -> bool {
                          if (t1[0] < t2[0])
                              return true;
                          else if (t1[0] == t2[0])
                              return t1[1] >= t2[1];
                          return false;
                      });

            auto temp = intervals[0];

            // O(n)
            // merge, e.g [(0,9), ...]
            for (int i = 1; i < len; i++) {
                if (intervals[i][0] >= temp[0] && intervals[i][0] <= temp[1]) {
                    temp[1] = std::max(temp[1], intervals[i][1]);

                } else if (intervals[i][0] > temp[1]) {
                    out.push_back(temp);
                    temp = intervals[i];
                }
            }

            out.push_back(temp);
            return out;
        }
    };
}  // namespace Leet::Medium
