#pragma once

#include <queue>
#include <unordered_set>
#include <vector>

using std::queue;
using std::unordered_set;
using std::vector;

namespace Leet::Medium {
    struct ValidGraph_UnionFind
    {
        vector<int> parent;
        vector<int> rank;

        ValidGraph_UnionFind(int n) : parent(n), rank(n)
        {
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        int findParent(int n)
        {
            if (parent[n] == n)
                return n;
            return parent[n] = findParent(parent[n]);
        }

        bool unionMerge(int u, int v)
        {
            int parent_u = findParent(u);
            int parent_v = findParent(v);

            if (parent_u == parent_v)
                return false;

            if (rank[parent_u] >= rank[parent_v]) {
                parent[v] = parent_u;
                rank[u]++;
            } else {
                parent[u] = parent_v;
                rank[v]++;
            }

            return true;
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

    struct GraphValidTree
    {
        // UnionFind solution
        // treat each node as a disjointed set. Go through and connect each node based on
        // the edge. if it's a tree we should have only one set left.
        bool validTree(int n, vector<vector<int>>& edges)
        {
            // this property still holds, but is not needed since we count the number of
            // sets at the end
            // if (edges.size() != n - 1)
            //     return false;

            ValidGraph_UnionFind uf(n);

            for (vector<int> edge : edges) {
                if (!uf.unionMerge(edge[0], edge[1]))
                    return false;
            }

            // if we have more the one set, they are disjointed and no edge existed to
            // connect them
            return uf.count() == 1;
        }

        // BFS solution
        // Basic BFS, just traverse through the graph, and at the end see if we have
        // reached every node. The only time it's false (other that the edge to node
        // count) is if we have disjointed sets
        bool validTree_BFS(int n, vector<vector<int>>& edges)
        {
            // fundamental property of trees. The number of edges is 1 less than the
            // number of nodes
            if (edges.size() != n - 1)
                return false;

            queue<int> q;
            unordered_set<int> seen;
            vector<vector<int>> graph(n);

            for (vector<int> edge : edges) {
                int u = edge[0];
                int v = edge[1];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }

            q.push(0);
            seen.insert(0);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (seen.count(v) == 0) {
                        q.push(v);
                        seen.insert(v);
                    }
                }
            }

            return seen.size() == n;
        }
    };
}  // namespace Leet::Medium