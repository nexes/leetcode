#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Leet::Medium {
    using std::string;
    using std::unordered_map;
    using std::unordered_set;
    using std::vector;

    // Given a list of strings words and a string pattern, return a list of words[i] that
    // match pattern. You may return the answer in any order.

    // A word matches the pattern if there exists a permutation of letters p so that after
    // replacing every letter x in the pattern with p(x), we get the desired word.

    // Recall that a permutation of letters is a bijection from letters to letters: every
    // letter maps to another letter, and no two letters map to the same letter.

    // Example 1:
    // Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
    // Output: ["mee","aqq"]
    //
    // Explanation: "mee" matches the pattern because there is a permutation {a -> m, b ->
    // e, ...}. "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a
    // permutation, since a and b map to the same letter.

    // Example 2:
    // Input: words = ["a","b","c"], pattern = "a"
    // Output: ["a","b","c"]

    // Constraints:
    // 1 <= pattern.length <= 20
    // 1 <= words.length <= 50
    // words[i].length == pattern.length
    // pattern and words[i] are lowercase English letters.
    struct FindReplacePattern
    {
        vector<string> findAndReplacePattern(vector<string>& words, string pattern)
        {
            bool add_word;
            vector<string> results{};
            unordered_map<char, char> patt_to_word{};
            unordered_map<char, char> word_to_patt{};

            for (const auto word : words) {
                add_word = true;

                // clear our maps
                patt_to_word.clear();
                word_to_patt.clear();

                for (int i = 0; i < word.size(); i++) {
                    auto patt_it = patt_to_word.emplace(pattern[i], word[i]);
                    auto word_it = word_to_patt.emplace(word[i], pattern[i]);

                    if (!patt_it.second || !word_it.second) {
                        auto patt_value = patt_to_word[pattern[i]];
                        auto word_value = word_to_patt[patt_value];

                        if (word_value != pattern[i] || patt_value != word[i]) {
                            add_word = false;
                            break;
                        }
                    }
                }

                if (add_word)
                    results.emplace_back(word);
            }

            return results;
        }

        // this will work if we are not worried about the positions of the characters in
        // our word
        // vector<string> findAndReplacePattern(vector<string>& words, string pattern)
        // {
        //     vector<string> results{};
        //     int pattern_len = count_uniques(pattern);

        //     // O(n*k)
        //     for (const auto word : words) {
        //         if (count_uniques(word) == pattern_len)
        //             results.emplace_back(word);
        //     }

        //     return results;
        // }

        // // O(n)
        // int count_uniques(string word)
        // {
        //     unordered_set<char> unique{};

        //     for (const auto c : word)
        //         unique.emplace(c);

        //     return unique.size();
        // }
    };
}  // namespace Leet::Medium
