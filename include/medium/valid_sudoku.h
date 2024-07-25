#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

namespace Leet::Medium {
    struct ValidSudoku
    {
        bool check_row(vector<char> &row)
        {
            string nums = "0123456789";

            for (char c : row) {
                if (c == '.')
                    continue;

                if (nums[c - '0'] != c)
                    return false;
                nums[c - '0'] = 'x';
            }

            return true;
        }

        bool check_col(vector<vector<char>> &board, int col)
        {
            string nums = "0123456789";

            for (int row = 0; row < board.size(); row++) {
                char c = board[row][col];
                if (c == '.')
                    continue;

                if (c != nums[c - '0'])
                    return false;
                nums[c - '0'] = 'x';
            }

            return true;
        }

        bool check_square(vector<vector<char>> &board, int row, int col)
        {
            string nums = "0123456789";

            for (int i = row; i < row + 3; i++) {
                for (int j = col; j < col + 3; j++) {
                    char c = board[i][j];
                    if (c == '.')
                        continue;

                    if (c != nums[c - '0'])
                        return false;
                    nums[c - '0'] = 'x';
                }
            }

            return true;
        }

        // verbose approach but passes
        bool isValidSudoku_verbose(vector<vector<char>> &board)
        {
            for (int i = 0; i < board.size(); i++)
                if (!check_row(board[i]))
                    return false;

            for (int i = 0; i < board.size(); i++)
                if (!check_col(board, i))
                    return false;

            for (int i = 0; i < board.size(); i += 3) {
                for (int j = 0; j < board.size(); j += 3) {
                    if (!check_square(board, i, j)) {
                        return false;
                    }
                }
            }

            return true;
        }

        // shorter solution
        bool isValidSudoku(vector<vector<char>> &board)
        {
            unordered_map<int, unordered_set<char>> row(9);
            unordered_map<int, unordered_set<char>> col(9);
            unordered_map<int, unordered_set<char>> grid(9);

            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j] == '.')
                        continue;

                    if (row[i].count(board[i][j]) || col[j].count(board[i][j]) ||
                        grid[(i / 3) * 3 + (j / 3)].count(board[i][j]))
                        return false;

                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    grid[(i / 3) * 3 + (j / 3)].insert(board[i][j]);
                }
            }

            return true;
        }
    };
}  // namespace Leet::Medium