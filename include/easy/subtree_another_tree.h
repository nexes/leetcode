#pragma once

#include "../treenode.h"

namespace Leet::Easy {
    // Given the roots of two binary trees root and subRoot, return true if there is a
    // subtree of root with the same structure and node values of subRoot and false
    // otherwise. A subtree of a binary tree tree is a tree that consists of a node in
    // tree and all of this node's descendants. The tree tree could also be considered as
    // a subtree of itself.

    // Example 1:
    // Input: root = [3,4,5,1,2], subRoot = [4,1,2]
    // Output: true

    // Example 2:
    // Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
    // Output: false

    // Constraints:
    // The number of nodes in the root tree is in the range [1, 2000].
    // The number of nodes in the subRoot tree is in the range [1, 1000].
    // -104 <= root.val <= 104
    // -104 <= subRoot.val <= 104
    struct SubtreeTree
    {
        bool helper(Leet::TreeNode *root, Leet::TreeNode *subRoot)
        {
            if (root == nullptr && subRoot == nullptr)
                return true;

            if (root == nullptr || subRoot == nullptr)
                return false;

            if (root->val != subRoot->val)
                return false;

            return helper(root->left, subRoot->left) &&
                   helper(root->right, subRoot->right);
        }

        bool isSubTree(Leet::TreeNode *root, Leet::TreeNode *subRoot)
        {
            if (root == nullptr)
                return false;

            if (helper(root, subRoot))
                return true;

            return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
        }
    };
}  // namespace Leet::Easy