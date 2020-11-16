#pragma once

#include <../treenode.h>

#include <queue>

namespace Leet::Easy {
    // In a binary tree, the root node is at depth 0, and children of each depth k
    // node are at depth k+1. Two nodes of a binary tree are cousins if they have
    // the same depth, but have different parents. We are given the root of a binary
    // tree with unique values, and the values x and y of two different nodes in the tree.
    // Return true if and only if the nodes corresponding to the values x and y are cousins.

    // Example 1:
    // Input: root = [1,2,3,4], x = 4, y = 3
    // Output: false

    // Example 2:
    // Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
    // Output: true

    // Example 3:
    // Input: root = [1,2,3,null,4], x = 2, y = 3
    // Output: false

    // Constraints:
    // The number of nodes in the tree will be between 2 and 100.
    // Each node has a unique integer value from 1 to 100.
    struct CousinsTree
    {
        bool isCousins(Leet::TreeNode* root, int x, int y)
        {
            auto q = std::queue<Leet::TreeNode*>{};
            Leet::TreeNode* parent_x = nullptr;
            Leet::TreeNode* parent_y = nullptr;
            int level_x = 0;
            int level_y = 0;
            int level = 0;

            q.emplace(root);

            while (!q.empty()) {
                int len = q.size();

                // level i
                for (int i = 0; i < len; i++) {
                    auto curr = q.front();
                    q.pop();

                    if (!curr) continue;

                    if (curr->left && curr->left->val == x || curr->right && curr->right->val == x) {
                        parent_x = curr;
                        level_x = level;
                    }
                    if (curr->left && curr->left->val == y || curr->right && curr->right->val == y) {
                        parent_y = curr;
                        level_y = level;
                    }

                    q.emplace(curr->left);
                    q.emplace(curr->right);
                }

                level++;
            }

            if (level_x == level_y)
                return (parent_x && parent_y && parent_x != parent_y);

            return false;
        }
    };
}  // namespace Leet::Easy
