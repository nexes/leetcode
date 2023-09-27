#pragma once

#include <vector>

using std::vector;

namespace Leet::Easy {
    // You are given a 2D integer array logs where each logs[i] = [birthi,
    // deathi] indicates the birth and death years of the ith person.

    // The population of some year x is the number of people alive during that
    // year. The ith person is counted in year x's population if x is in the
    // inclusive range [birthi, deathi - 1]. Note that the person is not counted
    // in the year that they die.

    // Return the earliest year with the maximum population.

    // Example 1:
    // Input: logs = [[1993,1999],[2000,2010]]
    // Output: 1993
    // Explanation: The maximum population is 1, and 1993 is the earliest year
    // with this population.

    // Example 2:
    // Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
    // Output: 1960
    // Explanation:
    // The maximum population is 2, and it had happened in years 1960 and 1970.
    // The earlier year between them is 1960.

    // Constraints:
    // 1 <= logs.length <= 100
    // 1950 <= birthi < deathi <= 2050
    struct MaxPopulationYear
    {
        // a prefix sum problem
        int maximumPopulation(vector<vector<int>> &logs)
        {
            int year = 1950;
            int maxPopulation = 0;
            int prefix[101] = {};

            // setup initial birth year to +1 and death year -1
            for (auto log : logs) {
                prefix[log[0] - 1950]++;
                prefix[log[1] - 1950]--;
            }

            maxPopulation = prefix[0];

            // calculate the prefix sum array
            for (int i = 1; i < 101; i++) {
                prefix[i] += prefix[i - 1];

                if (prefix[i] > maxPopulation) {
                    maxPopulation = prefix[i];
                    year = 1950 + i;
                }
            }

            return year;
        }
    };
}  // namespace Leet::Easy
