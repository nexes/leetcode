#pragma once

#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

namespace Leet::Medium {
    // Given an array of points where points[i] = [xi, yi] represents a point on the X-Y
    // plane and an integer k, return the k closest points to the origin (0, 0). The
    // distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1
    // - x2)2 + (y1 - y2)2).

    // You may return the answer in any order. The answer is guaranteed to be unique
    // (except for the order that it is in).

    // Example 1:
    // Input: points = [[1,3],[-2,2]], K = 1
    // Output: [[-2,2]]
    // Explanation:
    // The distance between (1, 3) and the origin is sqrt(10).
    // The distance between (-2, 2) and the origin is sqrt(8).
    // Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
    // We only want the closest K = 1 points from the origin, so the answer is just
    // [[-2,2]].

    // Example 2:
    // Input: points = [[3,3],[5,-1],[-2,4]], K = 2
    // Output: [[3,3],[-2,4]]
    // (The answer [[-2,4],[3,3]] would also be accepted.)

    // Note:
    // 1 <= K <= points.length <= 10000
    // -10000 < points[i][0] < 10000
    // -10000 < points[i][1] < 10000
    struct KClosestPoint
    {
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
        {
            vector<vector<int>> closePoints;
            priority_queue<std::pair<int, int>, vector<std::pair<int, int>>,
                           std::greater<std::pair<int, int>>>
                distQueue;

            // O(n * log(n)) n = |points|,
            for (int i = 0; i < points.size(); i++) {
                int x = points[i][0];
                int y = points[i][1];
                int dist = (x * x) + (y * y);

                distQueue.push({dist, i});
            }

            // O(k * log(k))
            for (int i = 0; i < k; i++) {
                auto [dist, index] = distQueue.top();
                distQueue.pop();

                closePoints.push_back(points[index]);
            }

            return closePoints;
        }
    };
}  // namespace Leet::Medium
