#pragma once

#include <../treenode.h>

#include <algorithm>

namespace Leet::Easy {
    // Given a binary tree, determine if it is height-balanced.
    // For this problem, a height-balanced binary tree is defined as:
    // a binary tree in which the left and right subtrees of every node differ in height
    // by no more than 1.

    // Example 1:
    // Given the following tree [3,9,20,null,null,15,7]:

    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    // Return true.

    // Example 2:
    // Given the following tree [1,2,2,3,3,null,null,4,4]:

    //        1
    //       / \
    //      2   2
    //     / \
    //    3   3
    //   / \
    //  4   4
    // Return false
    struct BalancedTree
    {
        bool isBalanced(Leet::TreeNode *root)
        {
            if (!root) return true;

            int left = height(root->left);
            int right = height(root->right);

            if (std::abs(left - right) > 1) return false;

            return isBalanced(root->left) && isBalanced(root->right);
        }

        int height(Leet::TreeNode *root)
        {
            if (!root) return 0;

            int left = height(root->left);
            int right = height(root->right);

            return std::max(left, right) + 1;
        }
    };
}  // namespace Leet::Easy
