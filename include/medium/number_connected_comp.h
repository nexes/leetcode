#pragma once

#include <vector>

using std::vector;

namespace Prob {
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

        void unionMerge(int u, int v)
        {
            int uParent = findParent(u);
            int vParent = findParent(v);

            if (uParent == vParent)
                return;

            if (rank[uParent] >= rank[vParent]) {
                parent[vParent] = uParent;
                rank[uParent]++;
            } else {
                parent[uParent] = vParent;
                rank[vParent]++;
            }
        }

        int count()
        {
            int c = 0;

            for (int i = 0; i < parent.size(); i++)
                if (parent[i] == i)
                    c++;
            return c;
        }
    };
}  // namespace Prob

namespace Leet::Medium {
    // You have a graph of n nodes. You are given an integer n and an array edges where
    // edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

    // Return the number of connected components in the graph.

    // Example 1:
    // Input: n = 5, edges = [[0,1],[1,2],[3,4]]
    // Output: 2

    // Example 2:
    // Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
    // Output: 1

    // Constraints:
    // 1 <= n <= 2000
    // 1 <= edges.length <= 5000
    // edges[i].length == 2
    // 0 <= ai <= bi < n
    // ai != bi
    // There are no repeated edges.
    struct NumConnectedComp
    {
        int countComponents(int n, vector<vector<int>>& edges)
        {
            Prob::UnionFind uf(n);

            for (vector<int> edge : edges) {
                uf.unionMerge(edge[0], edge[1]);
            }

            return uf.count();
        }
    };
}  // namespace Leet::Medium