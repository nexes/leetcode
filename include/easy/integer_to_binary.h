#pragma once

#include <string>

namespace Leet::Easy {
    struct IntToBinary
    {
        std::string intToBinary(int n)
        {
            std::string binary;
            std::string bit;

            while (n > 0) {
                bit = n & 0x01 == 1 ? "1" : "0";
                binary = bit + binary;
                n = n >> 1;
            }

            return binary;
        }

        std::string intToBinaryReverse(int n)
        {
            std::string binary;

            while (n > 0) {
                binary += n & 0x01 == 1 ? "1" : "0";
                n = n >> 1;
            }

            return binary;
        }
    };
}  // namespace Leet::Easy