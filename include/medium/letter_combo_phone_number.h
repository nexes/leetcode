#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

namespace Leet::Medium {
    // Given a string containing digits from 2-9 inclusive, return all possible letter
    // combinations that the number could represent. Return the answer in any order.

    // A mapping of digits to letters (just like on the telephone buttons) is given below.
    // Note that 1 does not map to any letters.

    // Example 1:
    // Input: digits = "23"
    // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    // Example 2:
    // Input: digits = ""
    // Output: []

    // Example 3:
    // Input: digits = "2"
    // Output: ["a","b","c"]

    // Constraints:
    // 0 <= digits.length <= 4
    // digits[i] is a digit in the range ['2', '9'].
    struct LetterComboPhoneNum
    {
        void getCombination(vector<string>& output, unordered_map<char, string>& keyMap,
                            string& curr, string& digits, int idx)
        {
            if (curr.size() == digits.length()) {
                output.push_back(curr);
                return;
            }

            if (idx == digits.length())
                return;

            string letters = keyMap[digits[idx]];
            for (char c : letters) {
                curr.push_back(c);
                getCombination(output, keyMap, curr, digits, idx + 1);
                curr.pop_back();
            }
        }

        vector<string> letterCombinations(string digits)
        {
            vector<string> letters;
            string curr = "";

            unordered_map<char, string> keyMap{
                {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
            };

            if (!digits.empty())
                getCombination(letters, keyMap, curr, digits, 0);
            return letters;
        }
    };
}  // namespace Leet::Medium