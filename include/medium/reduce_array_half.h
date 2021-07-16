#pragma once

#include <iostream>
#include <queue>
#include <vector>

namespace Leet::Medium {
    // You are given an integer array arr. You can choose a set of integers
    // and remove all the occurrences of these integers in the array.
    // Return the minimum size of the set so that at least half of the
    // integers of the array are removed.

    // Example 1:
    // Input: arr = [3,3,3,3,5,5,5,2,2,7]
    // Output: 2
    // Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which
    // has size 5 (i.e equal to half of the size of the old array).
    // Possible sets of size 2 are {3,5},{3,2},{5,2}.
    // Choosing set {2,7} is not possible as it will make the new array
    // [3,3,3,3,5,5,5] which has size greater than half of the size of the old array.

    // Example 2:
    // Input: arr = [7,7,7,7,7,7]
    // Output: 1
    // Explanation: The only possible set you can choose is {7}. This will make
    // the new array empty.

    // Example 3:
    // Input: arr = [1,9]
    // Output: 1

    // Example 4:
    // Input: arr = [1000,1000,3,7]
    // Output: 1

    // Example 5:
    // Input: arr = [1,2,3,4,5,6,7,8,9,10]
    // Output: 5

    // Constraints:
    // 1 <= arr.length <= 105
    // arr.length is even.
    // 1 <= arr[i] <= 105
    struct ReduceArray
    {
        // time: O(nlog(n)) space: O(n)
        int minSetSize(std::vector<int>& arr)
        {
            std::vector<int> sizes{};
            int len = arr.size();
            int half_len = len / 2;

            std::sort(arr.begin(), arr.end());

            int curr = 1;
            for (int i = 1; i < len; i++) {
                if (arr[i] == arr[i - 1]) {
                    curr++;
                } else {
                    sizes.emplace_back(curr);
                    curr = 1;
                }
            }

            sizes.emplace_back(curr);

            std::sort(sizes.begin(), sizes.end(), std::greater<int>());

            int count = 0;
            for (int i = 0; i < sizes.size(); i++) {
                count++;
                len -= sizes[i];

                if (len <= half_len)
                    break;
            }

            return count;
        }
    };
}  // namespace Leet::Medium
