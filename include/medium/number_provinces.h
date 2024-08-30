#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {

    // Union Find disjoint-set data structure
    struct UnionFind
    {
        vector<int> parent;
        vector<int> size;

        UnionFind(int n)
        {
            parent = vector<int>(n);
            size = vector<int>(n, 1);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find_parent(int u)
        {
            if (parent[u] == u)
                return u;
            return parent[u] = find_parent(parent[u]);
        }

        void union_set(int u, int v)
        {
            int uparent = find_parent(u);
            int vparent = find_parent(v);

            if (uparent == vparent)
                return;

            if (size[uparent] >= size[vparent]) {
                parent[vparent] = uparent;
                size[uparent] += size[vparent];
            } else {
                parent[uparent] = vparent;
                size[vparent] += size[uparent];
            }
        }

        int count_sets()
        {
            int count = 0;
            for (int i = 0; i < parent.size(); i++)
                if (parent[i] == i)
                    count++;
            return count;
        }
    };

    // There are n cities. Some of them are connected, while some are not. If city a is
    // connected directly with city b, and city b is connected directly with city c, then
    // city a is connected indirectly with city c. A province is a group of directly or
    // indirectly connected cities and no other cities outside of the group. You are given
    // an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth
    // city are directly connected, and isConnected[i][j] = 0 otherwise.

    // Return the total number of provinces.

    // Example 1:
    // Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    // Output: 2

    // Example 2:
    // Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
    // Output: 3

    // Constraints:
    // 1 <= n <= 200
    // n == isConnected.length
    // n == isConnected[i].length
    // isConnected[i][j] is 1 or 0.
    // isConnected[i][i] == 1
    // isConnected[i][j] == isConnected[j][i]
    struct NumberOfProvinces
    {
        int findCircleNum(vector<vector<int>>& isConnected)
        {
            int size = isConnected.size();
            UnionFind uf(size);

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (isConnected[i][i] == 1 && isConnected[i][j] == 1)
                        uf.union_set(i, j);
                }
            }

            return uf.count_sets();
        }
    };
}  // namespace Leet::Medium