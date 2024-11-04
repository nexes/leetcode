#pragma once

#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

namespace Leet::Medium {
    // You are given a network of n nodes, labeled from 1 to n. You are also given times,
    // a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the
    // source node, vi is the target node, and wi is the time it takes for a signal to
    // travel from source to target.

    // We will send a signal from a given node k. Return the minimum time it takes for all
    // the n nodes to receive the signal. If it is impossible for all the n nodes to
    // receive the signal, return -1.

    // Example 1:
    // Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    // Output: 2

    // Example 2:
    // Input: times = [[1,2,1]], n = 2, k = 1
    // Output: 1

    // Example 3:
    // Input: times = [[1,2,1]], n = 2, k = 2
    // Output: -1

    // Constraints:
    // 1 <= k <= n <= 100
    // 1 <= times.length <= 6000
    // times[i].length == 3
    // 1 <= ui, vi <= n
    // ui != vi
    // 0 <= wi <= 100
    // All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
    struct NetworkDelay
    {
        // Dijkstra's algorithm
        int networkDelayTime(vector<vector<int>>& times, int n, int k)
        {
            vector<int> dist(n + 1, INT_MAX);
            vector<vector<std::pair<int, int>>> graph(n + 1, vector<std::pair<int, int>>(n + 1));
            priority_queue<std::pair<int, int>, vector<std::pair<int, int>>,
                           std::greater<std::pair<int, int>>> edgeQ;

            for (vector<int> time : times) {
                int u = time[0];
                int v = time[1];
                int w = time[2];
                graph[u].push_back({v, w});
            }

            dist[k] = 0;
            edgeQ.push({0, k});

            while (!edgeQ.empty()) {
                auto [cost, u] = edgeQ.top();
                edgeQ.pop();

                for (auto [v, weight] : graph[u]) {
                    if (weight + cost < dist[v]) {
                        dist[v] = weight + cost;
                        edgeQ.push({dist[v], v});
                    }
                }
            }

            int lastTime = -1;
            for (int i : dist) {
                lastTime = std::max(lastTime, i);
            }

            return lastTime == INT_MAX ? -1 : lastTime;
        }
    };
}  // namespace Leet::Medium