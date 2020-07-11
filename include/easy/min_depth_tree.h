#pragma once

#include <../treenode.h>

namespace Leet::Easy
{
    // Given a binary tree, find its minimum depth.
    // The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
    // Note: A leaf is a node with no children.

    // Example:
    // Given binary tree [3,9,20,null,null,15,7],
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    // return its minimum depth = 2
    struct MinDepthTree
    {
        int minDepth(Leet::TreeNode *root)
        {
            if (!root)
                return 0;

            int left = minDepth(root->left);
            int right = minDepth(root->right);

            if (left > 0 && right > 0)
                return std::min(left, right) + 1;
            return std::max(left, right) + 1;
        }
    };
} // namespace Leet::Easy
