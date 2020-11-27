#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace Leet::Hard {
    // Given two strings word1 and word2, return the minimum number of
    // operations required to convert word1 to word2.You have the following
    // three operations permitted on a word:
    //     Insert a character
    //     Delete a character
    //     Replace a character

    // Example 1:
    // Input: word1 = "horse", word2 = "ros"
    // Output: 3
    // Explanation:
    // horse -> rorse (replace 'h' with 'r')
    // rorse -> rose (remove 'r')
    // rose -> ros (remove 'e')

    // Example 2:
    // Input: word1 = "intention", word2 = "execution"
    // Output: 5
    // Explanation:
    // intention -> inention (remove 't')
    // inention -> enention (replace 'i' with 'e')
    // enention -> exention (replace 'n' with 'x')
    // exention -> exection (replace 'n' with 'c')
    // exection -> execution (insert 'u')

    // Constraints:
    // 0 <= word1.length, word2.length <= 500
    // word1 and word2 consist of lowercase English letters.
    struct EditDistance
    {
        // we will use the Levenshtein distance algorithm
        // https://en.wikipedia.org/wiki/Levenshtein_distance
        int minDistance(std::string word1, std::string word2)
        {
            auto map = std::vector<std::vector<int>>(
                word1.length() + 1,
                std::vector<int>(word2.length() + 1));

            for (int i = 0; i < map.size(); i++)
                map[i][0] = i;

            for (int i = 0; i < map[0].size(); i++)
                map[0][i] = i;

            for (int i = 1; i <= word1.length(); i++) {
                for (int j = 1; j <= word2.length(); j++) {
                    if (word1[i - 1] == word2[j - 1]) {
                        map[i][j] = map[i - 1][j - 1];

                    } else {
                        map[i][j] = 1 + std::min(map[i - 1][j],
                                                 std::min(map[i][j - 1], map[i - 1][j - 1]));
                    }
                }
            }

            return map[word1.length()][word2.length()];
        }
    };
}  // namespace Leet::Hard
