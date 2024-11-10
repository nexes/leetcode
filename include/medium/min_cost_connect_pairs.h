#pragma once

#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

namespace MCP {
    struct UnionFind
    {
        vector<int> parent;
        vector<int> rank;

        UnionFind(int n) : parent(n), rank(n)
        {
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int findParent(int n)
        {
            if (parent[n] == n)
                return n;
            return parent[n] = findParent(parent[n]);
        }

        bool unionMerge(int u, int v)
        {
            int uParent = findParent(u);
            int vParent = findParent(v);

            if (uParent == vParent)
                return false;

            if (rank[uParent] >= rank[vParent]) {
                parent[vParent] = uParent;
                rank[uParent]++;
            } else {
                parent[uParent] = vParent;
                rank[vParent]++;
            }

            return true;
        }
    };
}  // namespace MCP

namespace Leet::Medium {
    // You are given an array points representing integer coordinates of some points on a
    // 2D-plane, where points[i] = [xi, yi]. The cost of connecting two points [xi, yi]
    // and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where
    // |val| denotes the absolute value of val.

    // Return the minimum cost to make all points connected. All points are connected if
    // there is exactly one simple path between any two points.

    // Example 1:
    // Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
    // Output: 20
    // Explanation:

    // We can connect the points as shown above to get the minimum cost of 20.
    // Notice that there is a unique path between every pair of points.

    // Example 2:
    // Input: points = [[3,12],[-2,5],[-4,1]]
    // Output: 18

    // Constraints:
    // 1 <= points.length <= 1000
    // -106 <= xi, yi <= 106
    // All pairs (xi, yi) are distinct.
    struct MinCostConnectedPoints
    {
        // Kruskal's algorith to find the MST
        int minCostConnectPoints(vector<vector<int>>& points)
        {
            MCP::UnionFind uf(points.size());
            priority_queue<std::pair<int, vector<int>>,
                           vector<std::pair<int, vector<int>>>,
                           std::greater<std::pair<int, vector<int>>>>
                edgeQ;

            for (int i = 0; i < points.size(); i++) {
                for (int j = i + 1; j < points.size(); j++) {
                    int dist = std::abs(points[i][0] - points[j][0]) +
                               std::abs(points[i][1] - points[j][1]);

                    edgeQ.push({dist, {i, j}});
                }
            }

            int minCost = 0;
            while (!edgeQ.empty()) {
                auto [dist, edge] = edgeQ.top();
                edgeQ.pop();

                if (uf.unionMerge(edge[0], edge[1]))
                    minCost += dist;
            }

            return minCost;
        }
    };
}  // namespace Leet::Medium