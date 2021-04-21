#pragma once

#include <algorithm>

#include "../treenode.h"

namespace Leet::Easy {
    // Given the root of a binary tree, return the length of the diameter of the tree.
    // The diameter of a binary tree is the length of the longest path between any two
    // nodes in a tree. This path may or may not pass through the root. The length of a
    // path between two nodes is represented by the number of edges between them.

    // Example 1:
    // Input: root = [1,2,3,4,5]
    // Output: 3
    // Explanation: 3is the length of the path [4,2,1,3] or [5,2,1,3].

    // Example 2:
    // Input: root = [1,2]
    // Output: 1

    // Constraints:
    // The number of nodes in the tree is in the range [1, 104].
    // -100 <= Node.val <= 100
    struct DiameterTree
    {
        int diameterOfBinaryTree(Leet::TreeNode* root)
        {
            if (!root)
                return 0;

            int diameter = 0;
            height(root, diameter);

            return diameter;
        }

        int height(Leet::TreeNode* node, int& diameter)
        {
            if (!node)
                return 0;

            int left = height(node->left, diameter);
            int right = height(node->right, diameter);

            diameter = std::max(left + right, diameter);

            return std::max(left, right) + 1;
        }
    };
}  // namespace Leet::Easy
