#pragma once

#include <vector>

namespace Leet::Medium {

    // Given a non negative integer number num. For every numbers i in
    // the range 0 ≤ i ≤ num calculate the number of 1's in their binary
    // representation and return them as an array.

    // Example 1:
    // Input: 2
    // Output: [0,1,1]

    // Example 2:
    // Input: 5
    // Output: [0,1,1,2,1,2]

    // Follow up:
    // It is very easy to come up with a solution with run time O(n*sizeof(integer)).
    // But can you do it in linear time O(n) /possibly in a single pass?
    // Space complexity should be O(n).
    // Can you do it like a boss? Do it without using any builtin function
    // like __builtin_popcount in c++ or in any other language.
    struct CountBits
    {
        std::vector<int> countBits_naive(int num)
        {
            int count = 0;
            std::vector<int> out{0};

            // O(n*sizeof(integer))
            for (int i = 1; i <= num; i++)
            {
                int val = i;
                while (val > 0)
                {
                    if (val & 0x01) count++;
                    val = val >> 1;
                }

                out.push_back(count);
                count = 0;
            }

            return out;
        }

        std::vector<int> countBits(int num)
        {
            // note 1: x * 2 is the same as x << 1. Multiplying by 2 is the same as left shift
            // by 1. x and x*2 will have the same number of '1' bits
            // e.g 5: 0101, 10: 1010

            // to find 10;
            // 10: 1010
            // 10 / 2 = 5: 0101 (we have already found 5, by looking at 4, adding 1)
            // 10 and 5 will have the same number of '1' bits

            // note 2: all odd numbes will have the lsb turned off. the number of ones is an
            // odd number are the number of ones in the even number before it, plus one more

            int count = 0;
            std::vector<int> out(num + 1, 0);
            out[0] = 0;

            for (int i = 1; i <= num; i++)
            {
                if (i % 2 == 0)
                    out[i] = out[i / 2];
                else
                    out[i] = out[i - 1] + 1;
            }

            return out;
        }
    };
}  // namespace Leet::Medium
