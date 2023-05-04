#pragma once

#include <algorithm>
#include <vector>

using std::vector;

namespace Leet::Medium {
    // There are n gas stations along a circular route, where the amount of
    // gas at the ith station is gas[i].

    // You have a car with an unlimited gas tank and it costs cost[i] of gas to
    // travel from the ith station to its next (i + 1)th station. You begin the
    // journey with an empty tank at one of the gas stations.

    // Given two integer arrays gas and cost, return the starting gas station's
    // index if you can travel around the circuit once in the clockwise
    // direction, otherwise return -1. If there exists a solution, it is
    // guaranteed to be unique

    // Example 1:
    // Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
    // Output: 3
    // Explanation:
    // Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank =
    // 0 + 4 = 4 Travel to station 4. Your tank = 4 - 1 + 5 = 8 Travel to
    // station 0. Your tank = 8 - 2 + 1 = 7 Travel to station 1. Your tank = 7 -
    // 3 + 2 = 6 Travel to station 2. Your tank = 6 - 4 + 3 = 5 Travel to
    // station 3. The cost is 5. Your gas is just enough to travel back to
    // station 3. Therefore, return 3 as the starting index.

    // Example 2:
    // Input: gas = [2,3,4], cost = [3,4,3]
    // Output: -1
    // Explanation:
    // You can't start at station 0 or 1, as there is not enough gas to travel
    // to the next station. Let's start at station 2 and fill up with 4 unit of
    // gas. Your tank = 0 + 4 = 4 Travel to station 0. Your tank = 4 - 3 + 2 = 3
    // Travel to station 1. Your tank = 3 - 3 + 3 = 3
    // You cannot travel back to station 2, as it requires 4 unit of gas but you
    // only have 3. Therefore, you can't travel around the circuit once no
    // matter where you start.

    // Constraints:
    // n == gas.length == cost.length
    // 1 <= n <= 105
    // 0 <= gas[i], cost[i] <= 104
    struct GasStation
    {
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
        {
            int total_gas = 0;
            int total_cost = 0;
            int current = 0;
            int start_idx = 0;

            // the idea is you have to make a complete lap. So we will add up
            // how much gas that would take and how much cost (totals). At the
            // end if we have more cost than gas, we cant make a lap regarless
            // where we start. If we are negative at our current index than we
            // move our start index to the next one and reset our current gas.
            // As long as we are positive with our current gas our start index
            // wont move any more
            for (int i = 0; i < gas.size(); i++) {
                total_gas += gas[i];
                total_cost += cost[i];

                current += gas[i] - cost[i];

                if (current < 0) {
                    current = 0;
                    start_idx = i + 1;
                }
            }

            return (total_gas < total_cost) ? -1 : start_idx;
        }
    };
}  // namespace Leet::Medium