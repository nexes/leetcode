#pragma once

#include <vector>

namespace Leet::Easy {
    // A self-dividing number is a number that is divisible by every digit it contains.

    // For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and
    // 128 % 8 == 0. A self-dividing number is not allowed to contain the digit zero.

    // Given two integers left and right, return a list of all the self-dividing numbers
    // in the range [left, right].

    // Example 1:
    // Input: left = 1, right = 22
    // Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]

    // Example 2:
    // Input: left = 47, right = 85
    // Output: [48,55,66,77]

    // Constraints:
    // 1 <= left <= right <= 104
    struct SelfDividing
    {
        std::vector<int> selfDividingNumbers(int left, int right)
        {
            std::vector<int> nums;

            for (int i = left; i <= right; i++)
                if (checkNum(i))
                    nums.push_back(i);

            return nums;
        }

        bool checkNum(int num)
        {
            int original = num;

            while (num > 0) {
                int n = num % 10;
                num /= 10;

                if (n == 0 || original % n != 0)
                    return false;
            }

            return true;
        }
    };
}  // namespace Leet::Easy