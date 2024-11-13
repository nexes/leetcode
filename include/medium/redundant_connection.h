#pragma once

#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

namespace RC {
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
}  // namespace RC

namespace Leet::Medium {
    // In this problem, a tree is an undirected graph that is connected and has no cycles.
    // You are given a graph that started as a tree with n nodes labeled from 1 to n, with
    // one additional edge added. The added edge has two different vertices chosen from 1
    // to n, and was not an edge that already existed. The graph is represented as an
    // array edges of length n where edges[i] = [ai, bi] indicates that there is an edge
    // between nodes ai and bi in the graph.

    // Return an edge that can be removed so that the resulting graph is a tree of n
    // nodes. If there are multiple answers, return the answer that occurs last in the
    // input.

    // Example 1:
    // Input: edges = [[1,2],[1,3],[2,3]]
    // Output: [2,3]

    // Example 2:
    // Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
    // Output: [1,4]

    // Constraints:
    // n == edges.length
    // 3 <= n <= 1000
    // edges[i].length == 2
    // 1 <= ai < bi <= edges.length
    // ai != bi
    // There are no repeated edges.
    // The given graph is connected.
    struct RedundantConnection
    {
        // Union find
        vector<int> findRedundantConnection_unionFind(vector<vector<int>>& edges)
        {
            vector<int> cycleEdge;
            RC::UnionFind uf(edges.size() + 1);

            for (vector<int> edge : edges) {
                if (!uf.unionMerge(edge[0], edge[1])) {
                    cycleEdge.push_back(edge[0]);
                    cycleEdge.push_back(edge[1]);
                    break;
                }
            }

            return cycleEdge;
        }

        bool dfs(vector<vector<int>>& graph, unordered_set<int>& seen, int u, int v)
        {
            if (u == v)
                return true;

            seen.insert(u);
            for (int neighbor : graph[u]) {
                if (!seen.count(neighbor)) {
                    if (dfs(graph, seen, neighbor, v))
                        return true;
                }
            }

            return false;
        }

        // using DFS build the graph as we go
        vector<int> findRedundantConnection(vector<vector<int>>& edges)
        {
            vector<vector<int>> graph(edges.size() + 1);
            vector<int> cycle(2);

            for (vector<int> edge : edges) {
                unordered_set<int> seen;

                if (dfs(graph, seen, edge[0], edge[1]))
                    return edge;

                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }

            return cycle;
        }
    };
}  // namespace Leet::Medium