#pragma once

#include <queue>
#include <vector>

using std::queue;
using std::vector;

namespace Leet::Medium {
    // You are given an m x n grid rooms initialized with these three possible values.

    // -1 A wall or an obstacle.  0 A gate. INF Infinity means an empty room. We use the
    // value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to
    // a gate is less than 2147483647. Fill each empty room with the distance to its
    // nearest gate. If it is impossible to reach a gate, it should be filled with INF.

    // Example 1:
    // Input: rooms =
    // [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
    // Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

    // Example 2:
    // Input: rooms = [[-1]]
    // Output: [[-1]]

    // Constraints:
    // m == rooms.length
    // n == rooms[i].length
    // 1 <= m, n <= 250
    // rooms[i][j] is -1, 0, or 231 - 1.
    struct WallsAndGates
    {
        void wallsAndGates(vector<vector<int>>& rooms)
        {
            queue<std::pair<int, int>> roomQueue;
            vector<int> rowDir{-1, 1, 0, 0};
            vector<int> colDir{0, 0, 1, -1};

            // get starting points
            for (int i = 0; i < rooms.size(); i++) {
                for (int j = 0; j < rooms[0].size(); j++) {
                    if (rooms[i][j] == 0)
                        roomQueue.push({i, j});
                }
            }

            // BFS, we search from both starting places at the same time
            while (!roomQueue.empty()) {
                auto [i, j] = roomQueue.front();
                roomQueue.pop();

                for (int k = 0; k < 4; k++) {
                    int nextI = i + rowDir[k];
                    int nextJ = j + colDir[k];

                    if (nextI < 0 || nextJ < 0 || nextI >= rooms.size() ||
                        nextJ >= rooms[0].size())
                        continue;

                    // this acts as a 'seen' list
                    if (rooms[nextI][nextJ] != INT_MAX)
                        continue;

                    rooms[nextI][nextJ] = rooms[i][j] + 1;
                    roomQueue.push({nextI, nextJ});
                }
            }
        }
    };
}  // namespace Leet::Medium