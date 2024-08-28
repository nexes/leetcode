#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // You are given an undirected weighted graph of n nodes (0-indexed), represented by
    // an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a
    // and b with a probability of success of traversing that edge succProb[i]. Given two
    // nodes start and end, find the path with the maximum probability of success to go
    // from start to end and return its success probability.

    // If there is no path from start to end, return 0. Your answer will be accepted if it
    // differs from the correct answer by at most 1e-5.

    // Example 1:
    // Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end
    // = 2 Output: 0.25000 Explanation: There are two paths from start to end, one having
    // a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

    // Example 2:
    // Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end
    // = 2 Output: 0.30000

    // Example 3:
    // Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
    // Output: 0.00000
    // Explanation: There is no path between 0 and 2.

    // Constraints:
    // 2 <= n <= 10^4
    // 0 <= start, end < n
    // start != end
    // 0 <= a, b < n
    // a != b
    // 0 <= succProb.length == edges.length <= 2*10^4
    // 0 <= succProb[i] <= 1
    // There is at most one edge between every two nodes.
    struct MaxProbablity
    {
        // O(n*m)
        double maxProbability_bellman_ford(int n, vector<vector<int>> &edges,
                                           vector<double> &succProb, int start_node,
                                           int end_node)
        {
            bool changed = false;
            vector<double> prob(n);
            prob[start_node] = 1.0;

            for (int i = 0; i < n - 1; i++) {
                changed = false;
                for (int j = 0; j < edges.size(); j++) {
                    int u = edges[j][0];
                    int v = edges[j][1];
                    double edge_prob = succProb[j];
                    // relax
                    if (prob[v] < prob[u] * edge_prob) {
                        prob[v] = prob[u] * edge_prob;
                        changed = true;
                    }
                    if (prob[u] < prob[v] * edge_prob) {
                        prob[u] = prob[v] * edge_prob;
                        changed = true;
                    }
                }

                // if we have relaxed all edges we can stop
                if (!changed)
                    break;
            }

            return prob[end_node];
        }
    };
}  // namespace Leet::Medium