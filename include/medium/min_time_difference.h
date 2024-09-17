#pragma once

#include <string>
#include <vector>

namespace Leet::Medium {
    // Given a list of 24-hour clock time points in "HH:MM" format, return the minimum
    // minutes difference between any two time-points in the list.

    // Example 1:
    // Input: timePoints = ["23:59","00:00"]
    // Output: 1

    // Example 2:
    // Input: timePoints = ["00:00","23:59","00:00"]
    // Output: 0

    // Constraints:
    // 2 <= timePoints.length <= 2 * 104
    // timePoints[i] is in the format "HH:MM".
    struct MinTimeDifference
    {
        // O(nlog(n))
        int findMinDifference_sorting(std::vector<std::string>& timePoints)
        {
            int mindiff = INT_MAX;
            int n = timePoints.size();
            std::vector<int> timeMins;

            sort(timePoints.begin(), timePoints.end());
            for (std::string time : timePoints) {
                int mins = stoi(time.substr(3));
                int hours = stoi(time.substr(0, 2));
                timeMins.push_back((hours * 60) + mins);
            }

            for (int i = 1; i < timeMins.size(); i++)
                mindiff = std::min(mindiff, timeMins[i] - timeMins[i - 1]);

            // check first and last times (time wraps around)
            mindiff = std::min(mindiff, (timeMins[0] + (24 * 60)) - timeMins[n - 1]);
            return mindiff;
        }

        // time: O(n)
        // space: O(1)
        int findMinDifference(std::vector<std::string>& timePoints)
        {
            std::vector<bool> bucket(60 * 24, false);
            int min_diff = INT_MAX;

            // O(n)
            for (std::string time : timePoints) {
                int hours = stoi(time.substr(0, 2));
                int mins = stoi(time.substr(3));
                int idx = (hours * 60) + mins;

                // if we have already seen this time point
                if (bucket[idx] == true)
                    return 0;

                bucket[idx] = true;
            }

            // O(n)
            int first_time = -1;
            int prev_time = -1;
            for (int i = 0; i < bucket.size(); i++) {
                if (bucket[i] == true) {
                    if (prev_time == -1) {
                        first_time = i;
                        prev_time = i;
                    } else {
                        min_diff = std::min(min_diff, i - prev_time);
                        prev_time = i;
                    }
                }
            }

            // check first and last times (time wraps around)
            first_time += (24 * 60);
            min_diff = std::min(min_diff, first_time - prev_time);

            return min_diff;
        }
    };
}  // namespace Leet::Medium