#pragma once

#include <vector>

namespace Leet::Medium {
    // You are given an m x n matrix board containing letters 'X' and 'O', capture regions
    // that are surrounded:

    // Connect: A cell is connected to adjacent cells horizontally or vertically.
    // Region: To form a region connect every 'O' cell.
    // Surround: The region is surrounded with 'X' cells if you can connect the region
    // with 'X' cells and none of the region cells are on the edge of the board. A
    // surrounded region is captured by replacing all 'O's with 'X's in the input matrix
    // board.

    // Example 1:
    // Input: board =
    // [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]] Output:
    // [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
    // Explanation:
    // In the above diagram, the bottom region is not captured because it is on the edge
    // of the board and cannot be surrounded.

    // Example 2:
    // Input: board = [["X"]]
    // Output: [["X"]]

    // Constraints:
    // m == board.length
    // n == board[i].length
    // 1 <= m, n <= 200
    // board[i][j] is 'X' or 'O'.
    struct SurroundedRegions
    {
        void dfs(std::vector<std::vector<char>>& board, int i, int j)
        {
            int n = board.size();
            int m = board[0].size();

            if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O')
                return;

            board[i][j] = 'F';

            dfs(board, i - 1, j);
            dfs(board, i, j + 1);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
        }

        // the insight is instead of trying to find 'islands' of O's that we can change to
        // X's, find the O's on the boarders and search from there changing the to a temp
        // value we can change back to O's later. Change all other O's to X's
        void solve(std::vector<std::vector<char>>& board)
        {
            int n = board.size();
            int m = board[0].size();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == 'O') {
                        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                            dfs(board, i, j);
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == 'F') {
                        board[i][j] = 'O';

                    } else if (board[i][j] == 'O') {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    };
}  // namespace Leet::Medium