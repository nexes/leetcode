#pragma once

#include <string>
#include <vector>

namespace Leet::Medium {
    // An integer has sequential digits if and only if each digit in the number
    // is one more than the previous digit. Return a sorted list of all the
    // integers in the range [low, high] inclusive that have sequential digits.

    // Example 1:
    // Input: low = 100, high = 300
    // Output: [123,234]

    // Example 2:
    // Input: low = 1000, high = 13000
    // Output: [1234,2345,3456,4567,5678,6789,12345]

    // Constraints:
    // 10 <= low <= high <= 10^9
    struct SequentialDigit
    {
        int digit_length(int x)
        {
            int len = 0;

            while (x > 0)
            {
                x /= 10;
                len++;
            }

            return len;
        }

        // sliding window solution
        std::vector<int> sequentialDigits(int low, int high)
        {
            std::vector<int> out{};
            std::string digits_str = "123456789";

            int window_len = digit_length(low);

            for (int i = 0; i <= digits_str.length() - window_len; i++)
            {
                // we cannot have a window size greater than the digits_str "window"
                if (window_len > digits_str.length())
                    break;

                auto temp = std::stoi(digits_str.substr(i, window_len));

                if (temp >= low && temp <= high)
                    out.emplace_back(temp);

                // restart at 0 but with a window size of plus 1
                if (i == digits_str.length() - window_len)
                {
                    window_len++;
                    i = -1;
                }
            }

            return out;
        }
    };
}  // namespace Leet::Medium
