#pragma once

#include "../treenode.h"

namespace Leet::Medium {
    // Given the root of a binary tree, return the same tree where every subtree (of
    // the given tree) not containing a 1 has been removed.
    // A subtree of a node node is node plus every node that is a descendant of node.

    // Example 1:
    // Input: root = [1,null,0,0,1]
    // Output: [1,null,0,null,1]
    // Explanation:
    // Only the red nodes satisfy the property "every subtree not containing a 1".
    // The diagram on the right represents the answer.

    // Example 2:
    // Input: root = [1,0,1,0,0,0,1]
    // Output: [1,null,1,null,1]

    // Example 3:
    // Input: root = [1,1,0,1,1,0,1,0]
    // Output: [1,1,0,1,1,null,1]

    // Constraints:
    // The number of nodes in the tree is in the range [1, 200].
    // Node.val is either 0 or 1.
    struct BinaryTreePrune
    {
        Leet::TreeNode *pruneTree(Leet::TreeNode *root)
        {
            if (!helper(root))
                return nullptr;
            return root;
        }

        bool helper(Leet::TreeNode *node)
        {
            if (node == nullptr)
                return false;

            bool left = helper(node->left);
            bool right = helper(node->right);

            if (!left)
                node->left = nullptr;
            if (!right)
                node->right = nullptr;

            return left | right | node->val == 1;
        }
    };
}  // namespace Leet::Medium