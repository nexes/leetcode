#pragma once

namespace Leet::Easy {
    // Given a positive integer num, write a function which returns True if num
    // is a perfect square else False. Follow up: Do not use any built-in library
    // function such as sqrt.

    // Example 1:
    // Input: num = 16
    // Output: true

    // Example 2:
    // Input: num = 14
    // Output: false

    // Constraints:
    // 1 <= num <= 2^31 - 1
    struct PerfectSqr
    {
        // binary search our way to a perfect square if it exists
        bool isPerfectSquare(int num)
        {
            long low = 1;
            long high = num;
            long mid;

            while (low <= high) {
                mid = (high + low) / 2;

                if (mid * mid > num) {
                    high = mid - 1;

                } else if (mid * mid < num) {
                    low = mid + 1;

                } else {
                    return true;
                }
            }

            return false;
        }

        // easier to understand but slower solution.
        bool isPerfectSquare_slower(int num)
        {
            int limit = num / 2;

            if (num == 1)
                return true;

            for (long long i = 2; i <= limit; i++)
                if (i * i == num)
                    return true;

            return false;
        }
    };
}  // namespace Leet::Easy
