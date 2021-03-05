#pragma once

#include "../treenode.h"

namespace Leet::Medium {
    // Given the root of a binary tree, return the leftmost value in
    // the last row of the tree.

    // Example 1:
    // Input: root = [2,1,3]
    // Output: 1

    // Example 2:
    // Input: root = [1,2,3,4,null,5,6,null,null,7]
    // Output: 7

    // Constraints:
    // The number of nodes in the tree is in the range [1, 104].
    // -231 <= Node.val <= 231 - 1
    struct BottomLeft
    {
        int findBottomLeftValue(Leet::TreeNode* root)
        {
            if (!root)
                return 0;

            int value = 0;
            int max = 0;

            search(root, 1, max, value);

            return value;
        }

        void search(Leet::TreeNode* node, int level, int& maxLevel, int& value)
        {
            if (!node)
                return;

            if (level > maxLevel) {
                maxLevel = level;
                value = node->val;
            }

            search(node->left, level + 1, maxLevel, value);
            search(node->right, level + 1, maxLevel, value);
        }
    };
}  // namespace Leet::Medium
