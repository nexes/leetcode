#pragma once

#include <vector>

namespace Leet::Easy {

    // Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
    // The digits are stored such that the most significant digit is at the head of the list, and each element
    // in the array contain a single digit. You may assume the integer does not contain any leading zero, except
    // the number 0 itself.

    // Example 1:
    // Input: [1,2,3]
    // Output: [1,2,4]
    // Explanation: The array represents the integer 123.

    // Example 2:
    // Input: [4,3,2,1]
    // Output: [4,3,2,2]
    // Explanation: The array represents the integer 4321

    struct PlusOne
    {
        std::vector<int> plusone(std::vector<int> &digits)
        {
            std::vector<int> out = digits;
            int idx = out.size() - 1;
            bool carry = true;

            if (out.at(idx) != 9) {
                out.at(idx)++;

                return out;
            }

            while (carry) {
                if (idx >= 0 && out.at(idx) == 9) {
                    out.at(idx) = 0;
                    idx--;

                } else {
                    if (idx >= 0) {
                        out.at(idx)++;
                    } else {
                        out.insert(begin(out), 1);
                    }

                    carry = false;
                }
            }

            return out;
        }
    };
}  // namespace Leet::Easy
