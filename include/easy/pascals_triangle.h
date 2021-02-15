#pragma once

#include <vector>

namespace Leet::Easy {
    // Given a non-negative integer numRows, generate the first numRows of Pascal's
    // triangle. In Pascal's triangle, each number is the sum of the two numbers
    // directly above it.

    // Example:
    // Input: 5
    // Output:
    // [
    //      [1],
    //     [1,1],
    //    [1,2,1],
    //   [1,3,3,1],
    //  [1,4,6,4,1]
    // ]
    struct PascalTriangle
    {
        std::vector<std::vector<int>> generate(int numRows)
        {
            std::vector<std::vector<int>> triangle{};

            if (numRows == 0)
                return triangle;

            std::vector<int> row{1};
            triangle.emplace_back(row);

            for (int i = 1; i < numRows; i++) {
                std::vector<int> new_row{1};
                std::vector<int> prev_row = triangle[i - 1];

                for (int j = 1; j < i; j++) {
                    new_row.emplace_back(prev_row[j - 1] + prev_row[j]);
                }

                new_row.emplace_back(1);
                triangle.emplace_back(new_row);
            }

            return triangle;
        }
    };
}  // namespace Leet::Easy
