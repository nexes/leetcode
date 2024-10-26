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
            priority_queue<int, vector<int>, std::greater<int>> endTimes;
            int rooms = 1;

            sort(intervals.begin(), intervals.end());
            for (int i = 0; i < intervals.size(); i++) {
                while (!endTimes.empty() && endTimes.top() <= intervals[i][0])
                    endTimes.pop();

                endTimes.push(intervals[i][1]);
                rooms = std::max(rooms, (int)endTimes.size());
            }

            return rooms;
        }

        // set all start times with a +1 and all end times with a -1. Place all start and
        // end times in an array and sort. When we have a start time that overlaps, +1
        // will tell us by how many. When an end time comes, it's decremented
        int minMeetingRooms_linesweep(vector<vector<int>>& intervals)
        {
            int rooms = 0;
            int totalRooms = 1;
            vector<std::pair<int, int>> sweep;

            for (vector<int> interval : intervals) {
                sweep.push_back({interval[0], 1});
                sweep.push_back({interval[1], -1});
            }

            sort(sweep.begin(), sweep.end());
            for (std::pair<int, int> s : sweep) {
                rooms += s.second;
                totalRooms = std::max(totalRooms, rooms);
            }

            return totalRooms;
        }
    };
}  // namespace Leet::Medium