#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace Leet::Easy {
    // Given an integer, write an algorithm to convert it to hexadecimal. For
    // negative integer, two’s complement method is used.

    // Note:
    // All letters in hexadecimal (a-f) must be in lowercase.
    // The hexadecimal string must not contain extra leading 0s. If the number
    // is zero, it is represented by a single zero character '0'; otherwise, the
    // first character in the hexadecimal string will not be the zero character.
    // The given number is guaranteed to fit within the range of a 32-bit signed
    // integer. You must not use any method provided by the library which
    // converts/formats the number to hex directly.

    // Example 1:
    // Input: 26
    // Output: "1a"

    // Example 2:
    // Input:  -1
    // Output: "ffffffff"
    struct ConvertToHex
    {
        std::string toHex(int num)
        {
            std::string hex;
            std::vector<char> hex_map{
                '0', '1', '2', '3', '4', '5', '6', '7',
                '8', '9', 'a', 'b', 'c', 'd', 'e', 'f',
            };

            if (num == 0)
                return "0";

            unsigned int x = num;
            while (x) {
                int rem = x % 16;
                hex.push_back(hex_map[rem]);
                x /= 16;
            }

            std::reverse(hex.begin(), hex.end());
            return hex;
        }

        std::string toHex_kinda_dumb(int num)
        {
            long lnum = num;
            std::string hex{""};
            std::vector<char> hex_map{
                '0', '1', '2', '3', '4', '5', '6', '7',
                '8', '9', 'a', 'b', 'c', 'd', 'e', 'f',
            };

            if (num == 0)
                return "0";

            if (num < 0)
                lnum = (0xffffffff ^ -lnum) + 1;

            while (lnum > 0) {
                hex = hex.insert(0, 1, hex_map[lnum & 0xf]);
                lnum = lnum >> 4;
            }

            return hex;
        }
    };
}  // namespace Leet::Easy
