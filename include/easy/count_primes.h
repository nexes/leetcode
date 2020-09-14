#pragma once

#include <vector>

namespace Leet::Easy {

    // Count the number of prime numbers less than a non-negative number, n.

    // Example:
    // Input: 10
    // Output: 4
    // Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
    struct CountPrimes
    {
        // using sieve of eratoshenes
        int countPrimes(int n)
        {
            std::vector<int> seive;
            int count;
            int size;

            for (int i = 2; i < n; i++)
                seive.push_back(i);

            size = seive.size();
            count = 0;

            for (int i = 0; i < size; i++)
            {
                int value = seive[i];

                if (value != -1)
                {
                    count++;
                    for (int j = value * 2 - 2; j < size; j += value)
                        seive[j] = -1;
                }
            }

            return count;
        }
    };
}  // namespace Leet::Easy
