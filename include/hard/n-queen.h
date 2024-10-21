#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Leet::Hard {
    // The n-queens puzzle is the problem of placing n queens on an n x n chessboard such
    // that no two queens attack each other. Given an integer n, return all distinct
    // solutions to the n-queens puzzle. You may return the answer in any order.

    // Each solution contains a distinct board configuration of the n-queens' placement,
    // where 'Q' and '.' both indicate a queen and an empty space, respectively.

    // Example 1:
    // Input: n = 4
    // Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    // Explanation: There exist two distinct solutions to the 4-queens puzzle as shown
    // above

    // Example 2:
    // Input: n = 1
    // Output: [["Q"]]

    // Constraints:
    // 1 <= n <= 9
    struct NQueen
    {
        // we are placing queens from top to bottom, left to right, so we don't need to
        // check to the right of us because we haven't reached those spots yet
        bool isSafe(vector<string>& board, int row, int col)
        {
            // check for Q's in the row
            for (int i = col; i >= 0; i--) {
                if (board[row][i] == 'Q')
                    return false;
            }

            // check for Q's in the col
            for (int i = row; i >= 0; i--) {
                if (board[i][col] == 'Q')
                    return false;
            }

            // check diagonal to bl
            int i = row;
            int j = col;
            while (i < board.size() && j >= 0) {
                if (board[i][j] == 'Q')
                    return false;
                i++;
                j--;
            }

            // check diagonal to tl
            i = row;
            j = col;
            while (i >= 0 && j >= 0) {
                if (board[i][j] == 'Q')
                    return false;
                i--;
                j--;
            }

            return true;
        }

        void solve(vector<vector<string>>& solved, vector<string>& board, int col)
        {
            if (col == board.size()) {
                solved.push_back(board);
                return;
            }

            for (int i = 0; i < board.size(); i++) {
                if (isSafe(board, i, col)) {
                    board[i][col] = 'Q';
                    solve(solved, board, col + 1);
                    board[i][col] = '.';
                }
            }
        }

        vector<vector<string>> solveNQueens(int n)
        {
            vector<vector<string>> solvedBoards;
            vector<string> board(n, string(n, '.'));

            solve(solvedBoards, board, 0);
            return solvedBoards;
        }
    };
}  // namespace Leet::Hard