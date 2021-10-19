#pragma once

#include <stack>
#include <string>

namespace Leet::Medium {
    // Given an encoded string, return its decoded string.

    // The encoding rule is: k[encoded_string], where the encoded_string inside the square
    // brackets is being repeated exactly k times. Note that k is guaranteed to be a
    // positive integer.

    // You may assume that the input string is always valid; No extra white spaces, square
    // brackets are well-formed, etc.

    // Furthermore, you may assume that the original data does not contain any digits and
    // that digits are only for those repeat numbers, k. For example, there won't be input
    // like 3a or 2[4].

    // Example 1:
    // Input: s = "3[a]2[bc]"
    // Output: "aaabcbc"

    // Example 2:
    // Input: s = "3[a2[c]]"
    // Output: "accaccacc"

    // Example 3:
    // Input: s = "2[abc]3[cd]ef"
    // Output: "abcabccdcdcdef"

    // Example 4:
    // Input: s = "abc3[cd]xyz"
    // Output: "abccdcdcdxyz"

    // Constraints:
    // 1 <= s.length <= 30
    // s consists of lowercase English letters, digits, and square brackets '[]'.
    // s is guaranteed to be a valid input.
    // All the integers in s are in the range [1, 300].
    struct DecodeString
    {
        std::string decodeString(std::string s)
        {
            int digit = 0;
            std::string word = "";
            std::stack<int> digit_stack;
            std::stack<std::string> word_stack;

            for (auto &c : s) {
                if (std::isalpha(c)) {
                    word.push_back(c);
                }

                if (std::isdigit(c)) {
                    digit *= 10;
                    digit += c - '0';
                }

                if (c == '[') {
                    digit_stack.push(digit);
                    word_stack.push(word);
                    digit = 0;
                    word = "";
                }

                if (c == ']') {
                    int last_digit = digit_stack.top();
                    digit_stack.pop();

                    std::string last_word = word_stack.top();
                    word_stack.pop();

                    for (int i = 0; i < last_digit; i++)
                        last_word += word;

                    word = last_word;
                }
            }

            return word;
        }
    };
}  // namespace Leet::Medium