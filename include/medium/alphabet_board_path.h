#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

namespace Leet::Medium {
    // On an alphabet board, we start at position (0, 0), corresponding to character
    // board[0][0].

    // Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the
    // diagram below.

    // We may make the following moves:

    // 'U' moves our position up one row, if the position exists on the board;
    // 'D' moves our position down one row, if the position exists on the board;
    // 'L' moves our position left one column, if the position exists on the board;
    // 'R' moves our position right one column, if the position exists on the board;
    // '!' adds the character board[r][c] at our current position (r, c) to the answer.
    // (Here, the only positions that exist on the board are positions with letters on
    // them.)

    // Return a sequence of moves that makes our answer equal to target in the minimum
    // number of moves.  You may return any path that does so.

    // Example 1:
    // Input: target = "leet"
    // Output: "DDR!UURRR!!DDD!"

    // Example 2:
    // Input: target = "code"
    // Output: "RR!DDRR!UUL!R!"

    // Constraints:
    // 1 <= target.length <= 100
    // target consists only of English lowercase letters.
    struct AlphabetBoardPath
    {
        string alphabetBoardPath(string target)
        {
            string path = "";
            unordered_map<char, std::pair<int, int>> charmap;
            vector<string> board{"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};

            for (int r = 0; r < board.size(); r++) {
                for (int c = 0; c < board[r].length(); c++) {
                    charmap[board[r][c]] = std::make_pair(r, c);
                }
            }

            int row = 0;
            int col = 0;
            for (char t : target) {
                int r = charmap[t].first;
                int c = charmap[t].second;

                path += string(std::max(0, col - c), 'L');
                path += string(std::max(0, r - row), 'D');
                path += string(std::max(0, row - r), 'U');
                path += string(std::max(0, c - col), 'R');
                path += "!";
                row = r;
                col = c;
            }

            return path;
        }
    };
}  // namespace Leet::Medium