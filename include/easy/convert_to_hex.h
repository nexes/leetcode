#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Leet::Easy {
    // Given an integer, write an algorithm to convert it to hexadecimal. For
    // negative integer, two’s complement method is used.

    // Note:
    // All letters in hexadecimal (a-f) must be in lowercase.
    // The hexadecimal string must not contain extra leading 0s. If the number is zero, it
    // is represented by a single zero character '0'; otherwise, the first character in
    // the hexadecimal string will not be the zero character. The given number is
    // guaranteed to fit within the range of a 32-bit signed integer. You must not use any
    // method provided by the library which converts/formats the number to hex directly.

    // Example 1:
    // Input: 26
    // Output: "1a"

    // Example 2:
    // Input:  -1
    // Output: "ffffffff"
    struct ConvertToHex
    {
        // convert to two's complement
        // Ignore sign and convert to binary system: 4(dec)=00000100(bin)=0x04(hex)
        // Invert, as the value is negative: 11111011(bin)=0xFB(hex)
        // Add 1, as figure is negative: 11111011(bin) + 00000001(bin) = 11111100(bin) =
        // 0xFC(hex)= -4(dec)
        std::string toHex(int num)
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
