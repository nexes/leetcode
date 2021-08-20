#pragma once

#include <numeric>
#include <vector>

namespace Leet::Medium {
    // Given an array of integers A and let n to be its length.
    // Assume Bk to be an array obtained by rotating the array A k positions clock-wise,
    // we define a "rotation function" F on A as follow:

    // F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
    // Calculate the maximum value of F(0), F(1), ..., F(n-1).

    // Note:
    // n is guaranteed to be less than 10^5.

    // Example:
    // A = [4, 3, 2, 6]
    // F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
    // F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
    // F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
    // F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
    // So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
    struct RotateFunc
    {
        // O(n^2) to slow for some tests
        int maxRotateFunction_n_squared(std::vector<int> &a)
        {
            int len = a.size();
            int rotate_idx = 0;
            int max_sum = 0;

            while (rotate_idx < len) {
                int sum = 0;

                for (int i = 0; i < len; i++) {
                    sum += a[(rotate_idx + i) % len] * i;
                }

                // cheap hack to take care of some edge cases
                if (rotate_idx == 0)
                    max_sum = sum;
                else
                    max_sum = std::max(max_sum, sum);

                rotate_idx++;
            }

            return max_sum;
        }

        // O(n)
        int maxRotateFunction(std::vector<int> &a)
        {
            long len = a.size();
            long sum = 0;

            // get the sum of the non rotated array
            for (int i = 0; i < len; i++)
                sum += a[i] * i;

            long arr_sum = std::accumulate(a.begin(), a.end(), 0);
            long temp = sum;

            // you can see this working if you look at the system of equations
            // F(0) = (0 * a) + (1 * b) + (2 * c) + (3 * d) + (4 * e) = 0 + b + 2c + 3d +
            // 4e F(1) = (1 * a) + (2 * b) + (3 * c) + (4 * d) + (0 * e) = a + 2b + 3c +
            // 4d + 0 F(2) = (2 * a) + (3 * b) + (4 * c) + (0 * d) + (1 * e) = 2a + 3b +
            // 4c + 0 + e etc
            for (int i = 1; i < len; i++) {
                temp = temp + arr_sum - len * a[len - i];
                sum = std::max(sum, temp);
            }

            return sum;
        }
    };
}  // namespace Leet::Medium
