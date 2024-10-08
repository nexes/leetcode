#pragma once

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

namespace Leet::Medium {
    // There are n cities numbered from 0 to n-1. Given the array edges where edges[i] =
    // [fromi, toi, weighti] represents a bidirectional and weighted edge between cities
    // fromi and toi, and given the integer distanceThreshold.

    // Return the city with the smallest number of cities that are reachable through some
    // path and whose distance is at most distanceThreshold, If there are multiple such
    // cities, return the city with the greatest number. Notice that the distance of a
    // path connecting cities i and j is equal to the sum of the edges' weights along that
    // path.

    // Example 1:
    // Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
    // Output: 3
    // Explanation: The figure above describes the graph.
    // The neighboring cities at a distanceThreshold = 4 for each city are:
    // City 0 -> [City 1, City 2]
    // City 1 -> [City 0, City 2, City 3]
    // City 2 -> [City 0, City 1, City 3]
    // City 3 -> [City 1, City 2]
    // Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to
    // return city 3 since it has the greatest number.

    // Example 2:
    // Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]],
    // distanceThreshold = 2 Output: 0 Explanation: The figure above describes the graph.
    // The neighboring cities at a distanceThreshold = 2 for each city are:
    // City 0 -> [City 1]
    // City 1 -> [City 0, City 4]
    // City 2 -> [City 3, City 4]
    // City 3 -> [City 2, City 4]
    // City 4 -> [City 1, City 2, City 3]
    // The city 0 has 1 neighboring city at a distanceThreshold = 2.

    // Constraints:
    // 2 <= n <= 100
    // 1 <= edges.length <= n * (n - 1) / 2
    // edges[i].length == 3
    // 0 <= fromi < toi < n
    // 1 <= weighti, distanceThreshold <= 10^4
    // All pairs (fromi, toi) are distinct.
    struct CitySmallestNeighbors
    {
        // Floyd-Warshall algorithm
        // time: O(n^3)
        int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
        {
            // graph setup
            vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

            // O(n)
            for (int i = 0; i < n; i++)
                graph[i][i] = 0;

            // O(n)
            for (int i = 0; i < edges.size(); i++) {
                vector<int> edge = edges[i];
                graph[edge[0]][edge[1]] = edge[2];
                graph[edge[1]][edge[0]] = edge[2];
            }

            // Floyd-Warshall algorithm
            // O(n^3)
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (graph[i][k] < INT_MAX && graph[k][j] < INT_MAX)
                            graph[i][j] =
                                std::min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }

            int count = n + 1;
            int node = 0;

            // answer the problem
            // O(n^2)
            for (int i = 0; i < n; i++) {
                int current_count = 0;
                for (int j = 0; j < n; j++) {
                    if (graph[i][j] <= distanceThreshold)
                        current_count++;
                }

                if (current_count <= count) {
                    count = current_count;
                    node = i;
                }
            }

            return node;
        }
    };
}  // namespace Leet::Medium