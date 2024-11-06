#pragma once

#include <queue>
#include <vector>

using std::queue;
using std::vector;

namespace Leet::Medium {
    // There is an m x n rectangular island that borders both the Pacific Ocean and
    // Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the
    // Atlantic Ocean touches the island's right and bottom edges. The island is
    // partitioned into a grid of square cells. You are given an m x n integer matrix
    // heights where heights[r][c] represents the height above sea level of the cell at
    // coordinate (r, c). The island receives a lot of rain, and the rain water can flow
    // to neighboring cells directly north, south, east, and west if the neighboring
    // cell's height is less than or equal to the current cell's height. Water can flow
    // from any cell adjacent to an ocean into the ocean.

    // Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that
    // rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

    // Example 1:
    // Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    // Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
    // Explanation: The following cells can flow to the Pacific and Atlantic oceans, as
    // shown below: [0,4]: [0,4] -> Pacific Ocean
    //        [0,4] -> Atlantic Ocean
    // [1,3]: [1,3] -> [0,3] -> Pacific Ocean
    //        [1,3] -> [1,4] -> Atlantic Ocean
    // [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
    //        [1,4] -> Atlantic Ocean
    // [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
    //        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
    // [3,0]: [3,0] -> Pacific Ocean
    //        [3,0] -> [4,0] -> Atlantic Ocean
    // [3,1]: [3,1] -> [3,0] -> Pacific Ocean
    //        [3,1] -> [4,1] -> Atlantic Ocean
    // [4,0]: [4,0] -> Pacific Ocean
    //        [4,0] -> Atlantic Ocean
    // Note that there are other possible paths for these cells to flow to the Pacific and
    // Atlantic oceans.

    // Example 2:
    // Input: heights = [[1]]
    // Output: [[0,0]]
    // Explanation: The water can flow from the only cell to the Pacific and Atlantic
    // oceans.

    // Constraints:
    // m == heights.length
    // n == heights[r].length
    // 1 <= m, n <= 200
    // 0 <= heights[r][c] <= 105
    struct PacificAtlanticFlow
    {
        void searchGraph(vector<vector<int>>& grid, queue<std::pair<int, int>>& q,
                         vector<vector<bool>>& seen)
        {
            vector<int> rowDir{-1, 1, 0, 0};
            vector<int> colDir{0, 0, 1, -1};

            while (!q.empty()) {
                auto [row, col] = q.front();
                q.pop();

                seen[row][col] = true;

                for (int k = 0; k < 4; k++) {
                    int nRow = row + rowDir[k];
                    int nCol = col + colDir[k];

                    if (nRow < 0 || nCol < 0 || nRow >= grid.size() ||
                        nCol >= grid[0].size())
                        continue;
                    if (seen[nRow][nCol])
                        continue;

                    if (grid[nRow][nCol] >= grid[row][col]) {
                        q.push({nRow, nCol});
                    }
                }
            }
        }

        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
        {
            vector<vector<int>> flow;
            queue<std::pair<int, int>> pacificQ;
            queue<std::pair<int, int>> atlanticQ;
            vector<vector<bool>> pacificSeen(heights.size(),
                                             vector<bool>(heights[0].size()));
            vector<vector<bool>> atlanticSeen(heights.size(),
                                              vector<bool>(heights[0].size()));

            // the top and bottom starting positions for both oceans
            for (int i = 0; i < heights[0].size(); i++) {
                pacificQ.push({0, i});
                atlanticQ.push({heights.size() - 1, i});
            }

            // the left and right starting positions for both oceans
            for (int i = 0; i < heights.size(); i++) {
                pacificQ.push({i, 0});
                atlanticQ.push({i, heights[0].size() - 1});
            }

            searchGraph(heights, pacificQ, pacificSeen);
            searchGraph(heights, atlanticQ, atlanticSeen);

            // the cells that were seen by both oceans will connect the oceans
            for (int i = 0; i < heights.size(); i++) {
                for (int j = 0; j < heights[0].size(); j++) {
                    if (pacificSeen[i][j] && atlanticSeen[i][j])
                        flow.push_back({i, j});
                }
            }

            return flow;
        }
    };
}  // namespace Leet::Medium