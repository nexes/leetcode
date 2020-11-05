#pragma once

#include <vector>

namespace Leet::Easy {
    // You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate
    // of a point. Check if these points make a straight line in the XY plane.

    // Example 1:
    // Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    // Output: true

    // Example 2:
    // Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
    // Output: false

    // Constraints:
    // 2 <= coordinates.length <= 1000
    // coordinates[i].length == 2
    // -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    // coordinates contains no duplicate point.
    struct StraightLine
    {
        bool checkStraightLine(std::vector<std::vector<int>>& coordinates)
        {
            double slope = 0.0;
            bool slope_undef = false;

            if (coordinates[1][0] - coordinates[0][0] == 0)
                slope_undef = true;
            else
                slope = double(coordinates[1][1] - coordinates[0][1]) / double(coordinates[1][0] - coordinates[0][0]);

            for (int i = 2; i < coordinates.size(); i++) {
                if (slope_undef) {
                    if (coordinates[i][0] != coordinates[i - 1][0])
                        return false;

                } else {
                    if (coordinates[i][0] - coordinates[i - 1][0] == 0)
                        return false;

                    double curr_slope = double(coordinates[i][1] - coordinates[i - 1][1]) / double(coordinates[i][0] - coordinates[i - 1][0]);

                    if (curr_slope != slope)
                        return false;
                }
            }

            return true;
        }
    };
}  // namespace Leet::Easy
