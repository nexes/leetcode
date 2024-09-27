#pragma once

#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

namespace Leet::Medium {
    // Given an array of meeting time intervals intervals where intervals[i] = [starti,
    // endi], return the minimum number of conference rooms required.

    // Example 1:
    // Input: intervals = [[0,30],[5,10],[15,20]]
    // Output: 2

    // Example 2:
    // Input: intervals = [[7,10],[2,4]]
    // Output: 1

    // Constraints:
    // 1 <= intervals.length <= 104
    // 0 <= starti < endi <= 106
    struct MettingRooms2
    {
        // sort by the start time. The pq is how we tell how many rooms are being used
        // we store the end times (min-heap) in the pq and if we have an overlap, we add a
        // new room to pq if not we remove the top of the pq and replace it with the new
        // meeting
        int minMeetingRooms(vector<vector<int>>& intervals)
        {
            int roomCount = 1;
            priority_queue<int, vector<int>, std::greater<int>> pq;

            sort(intervals.begin(), intervals.end());
            pq.push(intervals[0][1]);

            for (int i = 1; i < intervals.size(); i++) {
                int endSoon = pq.top();

                if (intervals[i][0] < endSoon)
                    roomCount++;
                else
                    pq.pop();

                pq.push(intervals[i][1]);
            }

            return pq.size();
        }
    };
}  // namespace Leet::Medium