#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace Leet::Medium {
    using std::vector;

    // Given a triangle array, return the minimum path sum from top to bottom.

    // For each step, you may move to an adjacent number of the row below. More
    // formally, if you are on index i on the current row, you may move to
    // either index i or index i + 1 on the next row.

    // Example 1:
    // Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    // Output: 11
    // Explanation: The triangle looks like:
    //    [2]
    //   [3] 4
    //  6 [5] 7
    // 4 [1] 8 3
    // The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
    // above).

    // Example 2:
    // Input: triangle = [[-10]]
    // Output: -10

    // Constraints:
    // 1 <= triangle.length <= 200
    // triangle[0].length == 1
    // triangle[i].length == triangle[i - 1].length + 1
    // -104 <= triangle[i][j] <= 104

    // Follow up: Could you do this using only O(n) extra space, where n is the
    // total number of rows in the triangle?
    struct Triangle
    {
        // ------------ RECUSION : TLE -------------------
        int findPath_recursion(vector<vector<int>> &triangle, int row, int col)
        {
            if (row == 0)
                return triangle[row][0];
            if (col < 0 || col >= triangle[row].size())
                return INT_MAX;

            return triangle[row][col] +
                   std::min(findPath_recursion(triangle, row - 1, col),
                            findPath_recursion(triangle, row - 1, col - 1));
        }

        int minimumTotal_recursion(vector<vector<int>> &triangle)
        {
            int rows = triangle.size();
            int pathTotal = INT_MAX;

            for (int i = 0; i < triangle[rows - 1].size(); i++)
                pathTotal =
                    std::min(pathTotal, findPath_recursion(triangle, rows - 1, i));

            return pathTotal;
        }

        // ------------ TOP DOWN : DP -----------------------
        int findPath_topdown(vector<vector<int>> &triangle, vector<vector<int>> &memo,
                             int row, int col)
        {
            if (row == 0)
                return triangle[row][0];
            if (col < 0 || col >= triangle[row].size())
                return INT_MAX;

            if (memo[row][col] != INT_MAX)
                return memo[row][col];

            memo[row][col] = triangle[row][col] +
                             std::min(findPath_topdown(triangle, memo, row - 1, col),
                                      findPath_topdown(triangle, memo, row - 1, col - 1));

            return memo[row][col];
        }

        int minimumTotal_topdown(vector<vector<int>> &triangle)
        {
            int rows = triangle.size();
            int pathTotal = INT_MAX;
            vector<vector<int>> memo(rows, vector<int>(rows, INT_MAX));

            // do our top down search starting from each index from the bottom row
            for (int i = 0; i < triangle[rows - 1].size(); i++)
                pathTotal =
                    std::min(pathTotal, findPath_topdown(triangle, memo, rows - 1, i));

            return pathTotal;
        }

        // ------------ BOTTOM UP : DP -----------------------
        int minimumTotal(vector<vector<int>> &triangle)
        {
            vector<vector<int>> dp(triangle);
            int rows = triangle.size();

            for (int i = rows - 2; i >= 0; i--) {
                for (int j = 0; j < triangle[i].size(); j++) {
                    int opt1 = triangle[i][j] + dp[i + 1][j];
                    int opt2 = triangle[i][j] + dp[i + 1][j + 1];

                    dp[i][j] = std::min(opt1, opt2);
                }
            }

            return dp[0][0];
        }
    };
}  // namespace Leet::Medium