#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Easy {
    // You are given an integer array arr. Sort the integers in the array in ascending
    // order by the number of 1's in their binary representation and in case of two or
    // more integers have the same number of 1's you have to sort them in ascending order.
    // Return the array after sorting it.

    // Example 1:
    // Input: arr = [0,1,2,3,4,5,6,7,8]
    // Output: [0,1,2,4,8,3,5,6,7]
    // Explantion: [0] is the only integer with 0 bits.
    // [1,2,4,8] all have 1 bit.
    // [3,5,6] have 2 bits.
    // [7] has 3 bits.
    // The sorted array by bits is [0,1,2,4,8,3,5,6,7]

    // Example 2:
    // Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
    // Output: [1,2,4,8,16,32,64,128,256,512,1024]
    // Explantion: All integers have 1 bit in the binary representation, you should just
    // sort them in ascending order.

    // Constraints:
    // 1 <= arr.length <= 500
    // 0 <= arr[i] <= 104
    struct SortIntByBits
    {
        // O(log(k)) k = num
        int count_ones(int num)
        {
            int count = 0;
            while (num > 0) {
                count += num & 0x01;
                num >>= 1;
            }

            return count;
        }

        std::vector<int> sortByBits(std::vector<int> &arr)
        {
            std::vector<std::pair<int, int>> nums;
            std::vector<int> sorted;

            // O(nlog(k))
            for (int i = 0; i < arr.size(); i++) {
                int ones = count_ones(arr[i]);
                nums.push_back({ones, arr[i]});
            }

            // O(nlog(n))
            std::sort(nums.begin(), nums.end());

            // O(n)
            for (auto pair : nums)
                sorted.push_back(pair.second);

            return sorted;
        }
    };
}  // namespace Leet::Easy