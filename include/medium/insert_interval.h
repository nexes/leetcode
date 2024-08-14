#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // You are given an array of non-overlapping intervals intervals where intervals[i] =
    // [starti, endi] represent the start and the end of the ith interval and intervals is
    // sorted in ascending order by starti. You are also given an interval newInterval =
    // [start, end] that represents the start and end of another interval.

    // Insert newInterval into intervals such that intervals is still sorted in ascending
    // order by starti and intervals still does not have any overlapping intervals (merge
    // overlapping intervals if necessary).

    // Return intervals after the insertion.

    // Note that you don't need to modify intervals in-place. You can make a new array and
    // return it.

    // Example 1:
    // Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    // Output: [[1,5],[6,9]]

    // Example 2:
    // Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    // Output: [[1,2],[3,10],[12,16]]
    // Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

    // Constraints:
    // 0 <= intervals.length <= 104
    // intervals[i].length == 2
    // 0 <= starti <= endi <= 105
    // intervals is sorted by starti in ascending order.
    // newInterval.length == 2
    // 0 <= start <= end <= 105
    struct InsertInterval
    {
        // time: O(n)
        vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInt)
        {
            vector<vector<int>> inserted;
            bool add_int = true;

            for (int i = 0; i < intervals.size(); i++) {
                // check if we have an overlapping interval
                if (newInt[0] <= intervals[i][1] && newInt[1] >= intervals[i][0]) {
                    newInt[0] = std::min(newInt[0], intervals[i][0]);
                    newInt[1] = std::max(newInt[1], intervals[i][1]);

                    // check if we found where our new interval belongs
                } else if (add_int && newInt[0] < intervals[i][0] &&
                           newInt[1] < intervals[i][0]) {
                    inserted.push_back(newInt);
                    inserted.push_back(intervals[i]);
                    add_int = false;

                    // insert the interval we're on
                } else {
                    inserted.push_back(intervals[i]);
                }
            }

            // insert our new interval if we haven't yet
            if (add_int)
                inserted.push_back(newInt);

            return inserted;
        }

        // time: O(n)
        vector<vector<int>> insert_another_way(vector<vector<int>> &intervals,
                                               vector<int> &newInt)
        {
            vector<vector<int>> inserted;
            int i = 0;

            // insert intervals before the newInt
            while (i < intervals.size() && intervals[i][1] < newInt[0])
                inserted.push_back(intervals[i++]);

            // iterate over the overlapping intervals if any
            while (i < intervals.size() && intervals[i][0] <= newInt[1]) {
                newInt[0] = std::min(newInt[0], intervals[i][0]);
                newInt[1] = std::max(newInt[1], intervals[i][1]);
                i++;
            }

            // insert our new interval
            inserted.push_back(newInt);

            // insert the rest
            while (i < intervals.size())
                inserted.push_back(intervals[i++]);

            return inserted;
        }
    };
}  // namespace Leet::Medium