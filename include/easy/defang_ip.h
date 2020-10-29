#pragma once

#include <string>

namespace Leet::Easy {
    // Given a valid (IPv4) IP address, return a defanged version of that IP address.
    // A defanged IP address replaces every period "." with "[.]".

    // Example 1:
    // Input: address = "1.1.1.1"
    // Output: "1[.]1[.]1[.]1"

    // Example 2:
    // Input: address = "255.100.50.0"
    // Output: "255[.]100[.]50[.]0"

    // Constraints:
    // The given address is a valid IPv4 address.
    struct Defang
    {
        std::string defangIPaddr(std::string address)
        {
            int pos = 0;
            int i = 0;

            while (i < 3) {
                pos = address.find(".", pos);
                address.replace(pos, 1, "[.]");
                pos += 3;
                i++;
            }

            return address;
        }
    };
}  // namespace Leet::Easy
