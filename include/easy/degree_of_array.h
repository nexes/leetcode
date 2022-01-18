#pragma once

#include <array>
#include <climits>
#include <unordered_map>
#include <vector>

namespace Leet::Easy {
    // Given a non-empty array of non-negative integers nums, the degree of this
    // array is defined as the maximum frequency of any one of its elements.

    // Your task is to find the smallest possible length of a (contiguous)
    // subarray of nums, that has the same degree as nums.

    // Example 1:
    // Input: nums = [1,2,2,3,1]
    // Output: 2
    // Explanation:
    // The input array has a degree of 2 because both elements 1 and 2 appear
    // twice. Of the subarrays that have the same degree: [1, 2, 2, 3, 1], [1,
    // 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2] The shortest length
    // is 2. So return 2.

    // Example 2:
    // Input: nums = [1,2,2,3,1,4,2]
    // Output: 6
    // Explanation:
    // The degree is 3 because the element 2 is repeated 3 times.
    // So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.

    // Constraints:
    // nums.length will be between 1 and 50,000.
    // nums[i] will be an integer between 0 and 49,999.
    struct DegreeArray
    {
        int findShortestSubArray(std::vector<int> &nums)
        {
            // freq[<nums[i], array<freq, first index, last index>]
            std::unordered_map<int, std::array<int, 3>> freq;
            int maxFreq = 1;

            for (int i = 0; i < nums.size(); i++) {
                // if this is a new number
                if (freq.find(nums[i]) == freq.end()) {
                    // insert the new frequency and the index
                    freq[nums[i]] = {1, i, i};
                } else {
                    // we need to update the frequency and the last index
                    // position
                    std::array<int, 3> value = freq[nums[i]];

                    // freq count
                    value[0]++;
                    // last index of this number
                    value[2] = i;
                    // assign new vector
                    freq[nums[i]] = value;

                    // keep track of the largest freq
                    maxFreq = std::max(maxFreq, value[0]);
                }
            }

            int smallest = INT_MAX;

            for (auto value : freq) {
                std::array<int, 3> data = value.second;

                if (data[0] == maxFreq)
                    smallest = std::min(smallest, data[2] - data[1] + 1);
            }

            return smallest;
        }
    };
}  // namespace Leet::Easy