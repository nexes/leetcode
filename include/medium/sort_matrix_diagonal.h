#pragma once

#include <algorithm>
#include <vector>

using std::vector;

namespace Leet::Medium {
    // A matrix diagonal is a diagonal line of cells starting from some cell in either the
    // topmost row or leftmost column and going in the bottom-right direction until
    // reaching the matrix's end. For example, the matrix diagonal starting from
    // mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and
    // mat[4][2]. Given an m x n matrix mat of integers, sort each matrix diagonal in
    // ascending order and return the resulting matrix.

    // Example 1:
    // Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
    // Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

    // Example 2:
    // Input: mat =
    // [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
    // Output:
    // [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
    struct SortMatrixDiagonal
    {
        void sort_diagonal(vector<vector<int>>& mat, int row, int col)
        {
            vector<int> sorted;

            int i = row;
            int j = col;
            // grab the values on the diagonal
            while (i < mat.size() && j < mat[i].size()) {
                sorted.push_back(mat[i][j]);
                i++;
                j++;
            }

            // sort the diagonal values
            std::sort(sorted.begin(), sorted.end());

            i = 0;
            // put them back
            while (row < mat.size() && col < mat[row].size()) {
                mat[row][col] = sorted[i++];
                row++;
                col++;
            }
        }

        vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
        {
            vector<vector<int>> sorted_mat = mat;
            int start_row = mat.size() - 1;
            int start_col = 0;

            while (start_row >= 0) {
                sort_diagonal(sorted_mat, start_row, start_col);
                start_row--;
            }

            start_row = 0;
            while (start_col < mat[start_row].size()) {
                sort_diagonal(sorted_mat, start_row, start_col);
                start_col++;
            }

            return sorted_mat;
        }
    };
}  // namespace Leet::Medium