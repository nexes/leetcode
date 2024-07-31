#pragma once

#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using std::vector;

namespace Leet::Medium {
    // Given an m x n binary matrix mat, return the distance of the nearest 0 for each
    // cell. The distance between two adjacent cells is 1.

    // Example 1:
    // Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
    // Output: [[0,0,0],[0,1,0],[0,0,0]]

    // Example 2:
    // Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
    // Output: [[0,0,0],[0,1,0],[1,2,1]]

    // Constraints:
    // m == mat.length
    // n == mat[i].length
    // 1 <= m, n <= 104
    // 1 <= m * n <= 104
    // mat[i][j] is either 0 or 1.
    // There is at least one 0 in mat.
    struct Matrix01
    {
        // time: O(n * m)
        vector<vector<int>> updateMatrix_bfs(vector<vector<int>> &mat)
        {
            int rowlen = mat.size();
            int collen = mat[0].size();
            std::set<std::pair<int, int>> seen;
            std::queue<std::pair<int, int>> q;

            // push all '0' cells onto the queue
            for (int i = 0; i < rowlen; i++)
                for (int j = 0; j < collen; j++)
                    if (mat[i][j] == 0)
                        q.push({i, j});

            // directions: left, up, right, down
            vector<int> dir{0, -1, 0, 1, 0};

            // BFS
            while (!q.empty()) {
                std::pair<int, int> cell = q.front();
                q.pop();

                // check the four neighbors
                for (int j = 0; j < 4; j++) {
                    int nr = cell.first + dir[j];
                    int nc = cell.second + dir[j + 1];

                    if (nr < 0 || nr >= rowlen || nc < 0 || nc >= collen ||
                        mat[nr][nc] == 0)
                        continue;
                    if (seen.count({nr, nc}) == 1)
                        continue;

                    mat[nr][nc] = mat[cell.first][cell.second] + 1;
                    seen.insert({nr, nc});
                    q.push({nr, nc});
                }
            }

            return mat;
        }

        // time: O(n^2)
        // correct but TLE
        vector<vector<int>> updateMatrix_backtrack(vector<vector<int>> &mat)
        {
            int rowlen = mat.size();
            int collen = mat[0].size();
            vector<vector<int>> matrix(rowlen, vector<int>(collen, 0));

            for (int i = 0; i < rowlen; i++) {
                for (int j = 0; j < collen; j++) {
                    if (mat[i][j] == 0)
                        continue;
                    matrix[i][j] = findZero(mat, i, j);
                }
            }

            return matrix;
        }

        int findZero(vector<vector<int>> &matrix, int row, int col)
        {
            if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size())
                return 10000;
            if (matrix[row][col] == 2)
                return 10000;
            if (matrix[row][col] == 0)
                return 0;

            matrix[row][col] = 2;

            int up = findZero(matrix, row - 1, col);
            int right = findZero(matrix, row, col + 1);
            int down = findZero(matrix, row + 1, col);
            int left = findZero(matrix, row, col - 1);

            matrix[row][col] = 1;

            return std::min(up, std::min(right, std::min(down, left))) + 1;
        }
    };
}  // namespace Leet::Medium