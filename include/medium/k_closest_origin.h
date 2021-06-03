#pragma once

#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

namespace Leet::Medium {
    // We have a list of points on the plane.  Find the K closest points to the origin (0,
    // 0). (Here, the distance between two points on a plane is the Euclidean distance.)
    // You may return the answer in any order.  The answer is guaranteed to be unique
    // (except for the order that it is in.)

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
        std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points,
                                               int k)
        {
            auto results = std::vector<std::vector<int>>{};
            auto dist_map = std::map<double, std::vector<std::vector<int>>>{};

            for (auto& point : points) {
                double dist = std::sqrt((point[0] * point[0]) + (point[1] * point[1]));
                auto point_bucket = std::vector<std::vector<int>>{
                    point,
                };

                if (auto it = dist_map.emplace(dist, point_bucket); !it.second) {
                    // collision
                    it.first->second.emplace_back(point);
                }
            }

            for (auto it = dist_map.begin(); it != dist_map.end(), k > 0; it++, k--) {
                if (it->second.size() == 1) {
                    results.emplace_back(it->second[0]);
                } else {
                    for (int i = 0; i<it->second.size(), k> 0; i++, k--)
                        results.emplace_back(it->second[i]);
                }
            }

            return results;
        }

        // cleaner but slower
        std::vector<std::vector<int>> kClosest_cleaner(
            std::vector<std::vector<int>>& points, int k)
        {
            auto results = std::vector<std::vector<int>>{};

            std::sort(points.begin(), points.end(),
                      [](const std::vector<int> a, const std::vector<int> b) {
                          double dist_a = std::sqrt((a[0] * a[0]) + (a[1] * a[1]));
                          double dist_b = std::sqrt((b[0] * b[0]) + (b[1] * b[1]));

                          return dist_a < dist_b;
                      });

            results.insert(results.end(), points.begin(), points.begin() + k);
            return results;
        }
    };
}  // namespace Leet::Medium
