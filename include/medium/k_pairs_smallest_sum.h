#pragma once

#include <queue>
#include <vector>

namespace Leet::Medium {
    using std::priority_queue;
    using std::vector;

    // You are given two integer arrays nums1 and nums2 sorted in ascending order and an
    // integer k. Define a pair (u, v) which consists of one element from the first array
    // and one element from the second array. Return the k pairs (u1, v1), (u2, v2), ...,
    // (uk, vk) with the smallest sums.

    // Example 1:
    // Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
    // Output: [[1,2],[1,4],[1,6]]
    // Explanation: The first 3 pairs are returned from the sequence:
    // [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

    // Example 2:
    // Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
    // Output: [[1,1],[1,1]]
    // Explanation: The first 2 pairs are returned from the sequence:
    // [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

    // Example 3:
    // Input: nums1 = [1,2], nums2 = [3], k = 3
    // Output: [[1,3],[2,3]]
    // Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]

    // Constraints:
    // 1 <= nums1.length, nums2.length <= 105
    // -109 <= nums1[i], nums2[i] <= 109
    // nums1 and nums2 both are sorted in ascending order.
    // 1 <= k <= 1000
    struct KPairsSmallSum
    {
        vector<vector<int>> kSmallestPairs_naive(vector<int> &nums1, vector<int> &nums2,
                                                 int k)
        {
            // <sum, [x, y]>
            priority_queue<std::pair<int, std::pair<int, int>>,
                           vector<std::pair<int, std::pair<int, int>>>,
                           std::greater<std::pair<int, std::pair<int, int>>>>
                pair_queue;

            vector<vector<int>> pairs;

            // brute force O(n^2) populate the priority queue
            for (int num1 : nums1) {
                for (int num2 : nums2) {
                    pair_queue.push({num1 + num2, {num1, num2}});
                }
            }

            vector<int> pair(2);
            int limit = std::min((int)pair_queue.size(), k);

            for (int i = 0; i < limit; i++) {
                auto top = pair_queue.top();
                pair_queue.pop();

                pair[0] = top.second.first;
                pair[1] = top.second.second;

                pairs.emplace_back(pair);
            }

            return pairs;
        }

        vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
        {
            // <sum, [x, y]>
            using sum_pair = std::pair<int, std::pair<int, int>>;

            vector<int> pair(2);
            vector<vector<int>> pairs;
            priority_queue<sum_pair, vector<sum_pair>, std::greater<sum_pair>> pair_queue;

            // pair_queue is a priority queue that will hold the sum and the indices where
            // that sum was found
            for (int i = 0; i < nums1.size(); i++)
                pair_queue.push({nums1[i] + nums2[0], {i, 0}});

            while (k-- && !pair_queue.empty()) {
                auto top_pair = pair_queue.top();

                pair[0] = nums1[top_pair.second.first];
                pair[1] = nums2[top_pair.second.second];
                pairs.emplace_back(pair);

                // we want to 'walk' down the second array, keeping the index in place
                // of the first array. We will create a new sum and place it into the
                // priority queue (this will put it in its place based on the sum).
                if (top_pair.second.second + 1 < nums2.size()) {
                    int first = top_pair.second.first;
                    int second = top_pair.second.second + 1;

                    pair_queue.push({nums1[first] + nums2[second], {first, second}});
                }

                pair_queue.pop();
            }

            return pairs;
        }
    };

}  // namespace Leet::Medium