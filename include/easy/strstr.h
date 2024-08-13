#pragma once

#include <string>
#include <vector>

namespace Leet::Easy {
    // Given two strings needle and haystack, return the index of the first occurrence of
    // needle in haystack, or -1 if needle is not part of haystack.

    // Example 1:
    // Input: haystack = "sadbutsad", needle = "sad"
    // Output: 0
    // Explanation: "sad" occurs at index 0 and 6.
    // The first occurrence is at index 0, so we return 0.

    // Example 2:
    // Input: haystack = "leetcode", needle = "leeto"
    // Output: -1
    // Explanation: "leeto" did not occur in "leetcode", so we return -1.

    // Constraints:
    // 1 <= haystack.length, needle.length <= 104
    // haystack and needle consist of only lowercase English characters.
    struct Str
    {
        // KMP algorithm, O(m + n): build the lsp
        std::vector<int> buildlsp(std::string needle)
        {
            int i = 1;
            int j = 0;
            std::vector<int> lsp(needle.length(), 0);

            while (i < needle.length()) {
                if (needle[i] == needle[j]) {
                    j++;
                    lsp[j] = j;
                    i++;
                } else if (j != 0) {
                    j = lsp[j - 1];
                } else {
                    lsp[i] = 0;
                    i++;
                }
            }

            return lsp;
        }

        // KMP algorithm, O(m + n): match the string
        int strStr(std::string haystack, std::string needle)
        {
            int i = 0;
            int j = 0;
            std::vector<int> lsp = buildlsp(needle);

            while (i < haystack.length() && j < needle.length()) {
                if (haystack[i] == needle[j]) {
                    i++;
                    j++;
                } else if (j != 0) {
                    j = lsp[j - 1];
                } else {
                    i++;
                }
            }

            if (j == needle.length())
                return i - j;

            return -1;
        }

        // naive solution
        int strStr_window(std::string haystack, std::string needle)
        {
            if (needle.empty())
                return 0;

            int hay_size = haystack.length();
            int needle_size = needle.length();

            for (int i = 0; i <= hay_size - needle_size; i++) {
                for (int j = 0; j < needle_size; j++) {
                    if (needle[j] != haystack[i + j])
                        break;

                    if (j + 1 == needle_size)
                        return i;
                }
            }

            return -1;
        }
    };
}  // namespace Leet::Easy
