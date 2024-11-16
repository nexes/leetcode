#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    struct FindThreeConsecutiveInts
    {
        // O(nlog(n))
        vector<long long> sumOfThree(long long num)
        {
            vector<long long> sums;
            long long low = 0;
            long long high = num;

            while (low <= high) {
                long long mid = low + (high - low) / 2;
                long long sum = (mid - 1) + mid + (mid + 1);

                if (sum == num) {
                    sums.push_back(mid - 1);
                    sums.push_back(mid);
                    sums.push_back(mid + 1);
                    break;
                }

                if (sum < num)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            return sums;
        }

        // O(1)
        vector<long long> sumOfThree_constant(long long num)
        {
            vector<long long> sums;

            if (num % 3 == 0) {
                long long mid = num / 3;
                sums.push_back(mid - 1);
                sums.push_back(mid);
                sums.push_back(mid + 1);
            }

            return sums;
        }
    };
}  // namespace Leet::Medium