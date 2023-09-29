#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // You are given an m x n matrix of characters box representing a side-view
    // of a box. Each cell of the box is one of the following:

    // A stone '#'
    // A stationary obstacle '*'
    // Empty '.'
    // The box is rotated 90 degrees clockwise, causing some of the stones to
    // fall due to gravity. Each stone falls down until it lands on an obstacle,
    // another stone, or the bottom of the box. Gravity does not affect the
    // obstacles' positions, and the inertia from the box's rotation does not
    // affect the stones' horizontal positions.

    // It is guaranteed that each stone in box rests on an obstacle, another
    // stone, or the bottom of the box. Return an n x m matrix representing the
    // box after the rotation described above.

    // Example 1:
    // Input: box = [["#",".","#"]]
    // Output: [["."],
    //          ["#"],
    //          ["#"]]

    // Example 2:
    // Input: box = [["#",".","*","."],
    //               ["#","#","*","."]]
    // Output: [["#","."],
    //          ["#","#"],
    //          ["*","*"],
    //          [".","."]]

    // Example 3:
    // Input: box = [["#","#","*",".","*","."],
    //               ["#","#","#","*",".","."],
    //               ["#","#","#",".","#","."]]
    // Output: [[".","#","#"],
    //          [".","#","#"],
    //          ["#","#","*"],
    //          ["#","*","."],
    //          ["#",".","*"],
    //          ["#",".","."]]

    // Constraints:
    // m == box.length
    // n == box[i].length
    // 1 <= m, n <= 500
    // box[i][j] is either '#', '*', or '.'.
    struct RotatingBox
    {
        vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
        {
            int row_len = box.size();
            int col_len = box[0].size();
            int empty_space = -1;
            vector<vector<char>> rotated;

            // let the stones fall
            // O(m*n)
            for (int row = 0; row < row_len; row++) {
                empty_space = -1;

                for (int col = col_len - 1; col >= 0; col--) {
                    switch (box[row][col]) {
                    case '*':
                        empty_space = -1;  // reset the empty space index
                        break;

                    case '.':
                        if (empty_space == -1)
                            empty_space = col;
                        break;

                    case '#':
                        if (empty_space != -1) {
                            box[row][col] = '.';
                            box[row][empty_space] = '#';

                            empty_space--;
                        }
                        break;
                    }
                }
            }

            // rotate the matrix
            for (int col = 0; col < col_len; col++) {
                vector<char> rr;

                for (int row = 0; row < row_len; row++) {
                    rr.emplace(rr.begin(), box[row][col]);
                }

                rotated.push_back(rr);
            }

            return rotated;
        }
    };
}  // namespace Leet::Medium