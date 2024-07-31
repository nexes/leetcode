#pragma once

#include <algorithm>
#include <queue>
#include <vector>

using std::vector;

namespace Leet::Medium {
    // Find the kth largest element in an unsorted array. Note that it is the
    // kth largest element in the sorted order, not the kth distinct element.

    // Example 1:
    // Input: [3,2,1,5,6,4] and k = 2
    // Output: 5

    // Example 2:
    // Input: [3,2,3,1,2,4,5,5,6] and k = 4
    // Output: 4

    // Note:
    // You may assume k is always valid, 1 ≤ k ≤ array's length.
    struct KthLargest
    {
        // time: O(nlog(n))
        int findKthLargest_sorted(std::vector<int> &nums, int k)
        {
            std::sort(nums.begin(), nums.end());
            return nums[nums.size() - k];
        }

        // using a priority queue and keeping the largest number on top
        // time: O(kLog(n))
        int findKthLargest_queue(std::vector<int> &nums, int k)
        {
            int largest = 0;
            std::priority_queue<int> pq(nums.begin(), nums.end());

            while (!pq.empty() && k-- > 0) {
                largest = pq.top();
                pq.pop();
            }

            return largest;
        }

        // time: O(n)
        // worst case: O(n^2)
        // quick select
        int findKthLargest(vector<int> &nums, int k)
        {
            int l = 0;
            int r = nums.size() - 1;
            int k_idx = nums.size() - k;

            auto partition = [&](vector<int> &nums, int l, int r) {
                // nums[r] is the pivot value
                for (int j = l; j < r; j++) {
                    if (nums[j] <= nums[r]) {
                        std::swap(nums[l], nums[j]);
                        l++;
                    }
                }
                std::swap(nums[l], nums[r]);
                return l;
            };

            int index = partition(nums, l, r);

            while (index != k_idx) {
                if (index < k_idx) {
                    l = index + 1;
                    index = partition(nums, l, r);
                }
                if (index > k_idx) {
                    r = index - 1;
                    index = partition(nums, l, r);
                }
            }

            return nums[index];
        }
    };
}  // namespace Leet::Medium
