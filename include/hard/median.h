#pragma once

#include <iostream>
#include <vector>

namespace Leet::Hard {

    // There are two sorted arrays nums1 and nums2 of size m and n respectively.
    // Find the median of the two sorted arrays. The overall run time complexity
    // should be O(log (m+n)). You may assume nums1 and nums2 cannot be both empty.
    //
    // Example 1:
    // nums1 = [1, 3]
    // nums2 = [2]
    //
    // The median is 2.0
    //
    // Example 2:
    // nums1 = [1, 2]
    // nums2 = [3, 4]
    // The median is (2 + 3)/2 = 2.5
    struct Median
    {
        double findMedianSortedArrays(std::vector<int> &num1, std::vector<int> &num2)
        {
            return 0.0;
        }

        double findMedianSortedArrays_slower(std::vector<int> &num1, std::vector<int> &num2)
        {
            std::vector<int> merged;
            std::merge(num1.begin(), num1.end(), num2.begin(), num2.end(), std::back_inserter(merged));

            // std::for_each(merged.begin(), merged.end(), [](const int &i) { std::cout << i << ", "; });

            return 0.0;
        }
    };
}  // namespace Leet::Hard
