#pragma once

#include <vector>

namespace Leet::Easy {
    // Given an array A of non-negative integers, return an array consisting of all the even
    // elements of A, followed by all the odd elements of A. You may return any answer array
    // that satisfies this condition.

    // Example 1:
    // Input: [3,1,2,4]
    // Output: [2,4,3,1]
    // The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

    // Note:
    // 1 <= A.length <= 5000
    // 0 <= A[i] <= 5000
    struct SortByParity
    {
        std::vector<int> sortArrayByParity(std::vector<int>& a)
        {
            int odd_idx = 0;

            for (int i = 0; i < a.size(); i++) {
                if (a[i] % 2 == 0) {
                    auto temp = a[i];
                    a[i] = a[odd_idx];
                    a[odd_idx] = temp;
                    odd_idx++;
                }
            }

            return a;
        }
    };
}  // namespace Leet::Easy
