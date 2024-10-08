#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Leet::Medium {
    // Given an m x n grid of characters board and a string word, return true if word
    // exists in the grid. The word can be constructed from letters of sequentially
    // adjacent cells, where adjacent cells are horizontally or vertically neighboring.
    // The same letter cell may not be used more than once.

    // Example 1:
    // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
    // "ABCCED" Output: true

    // Example 2:
    // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
    // "SEE" Output: true Example 3:

    // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
    // "ABCB" Output: false

    // Constraints:
    // m == board.length
    // n = board[i].length
    // 1 <= m, n <= 6
    // 1 <= word.length <= 15
    // board and word consists of only lowercase and uppercase English letters.

    // Follow up: Could you use search pruning to make your solution faster with a larger
    // board?
    struct WordSearch
    {
        bool search(vector<vector<char>>& board, vector<vector<bool>>& seen, string& word,
                    int i, int j, int idx)
        {
            if (idx == word.length())
                return true;

            if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
                board[i][j] != word[idx])
                return false;

            if (seen[i][j])
                return false;

            int dirRow[4] = {-1, 1, 0, 0};
            int dirCol[4] = {0, 0, 1, -1};

            for (int d = 0; d < 4; d++) {
                seen[i][j] = true;
                if (search(board, seen, word, i + dirRow[d], j + dirCol[d], idx + 1))
                    return true;
            }

            seen[i][j] = false;
            return false;
        }

        bool exist(vector<vector<char>>& board, string word)
        {
            vector<vector<bool>> seen(board.size(), vector<bool>(board[0].size(), false));

            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j] == word[0] && search(board, seen, word, i, j, 0))
                        return true;
                }
            }

            return false;
        }
    };
}  // namespace Leet::Medium