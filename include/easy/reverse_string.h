#pragma once

#include <vector>

namespace Leet::Easy {

    // Write a function that reverses a string. The input string is given as an
    // array of characters char[]. Do not allocate extra space for another array,
    // you must do this by modifying the input array in-place with O(1) extra memory.
    // You may assume all the characters consist of printable ascii characters.


    // Example 1:
    // Input: ["h","e","l","l","o"]
    // Output: ["o","l","l","e","h"]

    // Example 2:
    // Input: ["H","a","n","n","a","h"]
    // Output: ["h","a","n","n","a","H"]
    struct ReverseString
    {
        void reverseString(std::vector<char> &c)
        {
            int temp = 0;
            int left = 0;
            int right = c.size() - 1;

            while (left < right)
            {
                temp = c[left];
                c[left] = c[right];
                c[right] = temp;

                left++;
                right--;
            }
        }
    };
}
