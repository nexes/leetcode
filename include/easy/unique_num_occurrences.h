#pragma once

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

namespace Leet::Easy {
    // Given an array of integers arr, write a function that returns true if and only if
    // the number of occurrences of each value in the array is unique.

    // Example 1:
    // Input: arr = [1,2,2,1,1,3]
    // Output: true
    //
    // Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have
    // the same number of occurrences. Example 2:

    // Example 2:
    // Input: arr = [1,2]
    // Output: false

    // Example 3:
    // Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
    // Output: true

    // Constraints:
    // 1 <= arr.length <= 1000
    // -1000 <= arr[i] <= 1000
    struct UniqueOccurrences
    {
        // time: O(nlog(n))
        bool uniqueOccurrences(std::vector<int>& arr)
        {
            std::unordered_set<int> freq{};
            int count = 1;

            if (arr.size() == 1)
                return true;

            if (arr.size() == 2)
                return arr[0] == arr[1];

            // O(nlog(n))
            std::sort(arr.begin(), arr.end());

            for (int i = 1; i < arr.size(); i++) {
                if (arr[i - 1] == arr[i]) {
                    count++;
                } else {
                    if (auto it = freq.insert(count); !it.second)
                        return false;

                    count = 1;
                }
            }

            return true;
        }
    };
}  // namespace Leet::Easy
