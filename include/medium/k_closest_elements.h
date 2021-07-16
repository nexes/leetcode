#pragma once

#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

namespace Leet::Medium {
    // Given a sorted integer array arr, two integers k and x, return the k
    // closest integers to x in the array. The result should also be sorted
    // in ascending order.

    // An integer a is closer to x than an integer b if:
    // |a - x| < |b - x|, or
    // |a - x| == |b - x| and a < b

    // Example 1:
    // Input: arr = [1,2,3,4,5], k = 4, x = 3
    // Output: [1,2,3,4]

    // Example 2:
    // Input: arr = [1,2,3,4,5], k = 4, x = -1
    // Output: [1,2,3,4]

    // Constraints:
    // 1 <= k <= arr.length
    // 1 <= arr.length <= 104
    // arr is sorted in ascending order.
    // -104 <= arr[i], x <= 104
    struct KClosestElements
    {
        // correct but slow
        std::vector<int> findClosestElements_slow(std::vector<int>& arr, int k, int x)
        {
            std::vector<std::pair<int, int>> diffs{};
            std::vector<int> closest{};

            for (const auto& val : arr) {
                diffs.emplace_back(std::abs(val - x), val);
            }

            std::sort(diffs.begin(), diffs.end());

            for (int i = 0; i < k; i++)
                closest.push_back(diffs[i].second);

            std::sort(closest.begin(), closest.end());

            return closest;
        }

        std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x)
        {
            std::vector<int> elements{};
            int high = arr.size() - k;
            int low = 0;

            while (low < high) {
                int mid = (low + high) / 2;

                if (x - arr[mid] > arr[mid + k] - x)
                    low = mid + 1;
                else
                    high = mid;
            }

            for (int i = low; i < low + k; i++)
                elements.push_back(arr[i]);

            return elements;
        }
    };
}  // namespace Leet::Medium
