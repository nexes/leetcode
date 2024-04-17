#pragma once

#include "../treenode.h"

namespace Leet::Easy {
    // Given the root of a binary tree, return the sum of all left leaves.
    // A leaf is a node with no children. A left leaf is a leaf that is the left child of
    // another node.

    // Example 1:
    // Input: root = [3,9,20,null,null,15,7]
    // Output: 24
    // Explanation: There are two left leaves in the binary tree, with values 9 and 15
    // respectively. Example 2:

    // Input: root = [1]
    // Output: 0

    // Constraints:
    // The number of nodes in the tree is in the range [1, 1000].
    // -1000 <= Node.val <= 1000
    struct SumLeftLeaves
    {
        int sumOfLeftLeaves(Leet::TreeNode *root)
        {
            int sum = 0;
            sumHelper(root, sum, false);

            return sum;
        }

        void sumHelper(Leet::TreeNode *node, int &sum, bool isLeft)
        {
            if (node == nullptr)
                return;

            sumHelper(node->left, sum, true);
            sumHelper(node->right, sum, false);

            // if it's left and a leaf node
            if (isLeft && !node->left && !node->right)
                sum += node->val;
        }
    };
}  // namespace Leet::Easy