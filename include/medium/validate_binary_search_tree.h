#pragma once

#include <climits>
#include <vector>

#include "../treenode.h"

namespace Leet::Medium {
    // Given the root of a binary tree, determine if it is a valid binary search
    // tree (BST).

    // A valid BST is defined as follows:
    // The left subtree of a node contains only nodes with keys less than the
    // node's key. The right subtree of a node contains only nodes with keys
    // greater than the node's key. Both the left and right subtrees must also
    // be binary search trees.

    // Example 1:
    // Input: root = [2,1,3]
    // Output: true

    // Example 2:
    // Input: root = [5,1,4,null,null,3,6]
    // Output: false
    // Explanation: The root node's value is 5 but its right child's value is 4.

    // Constraints:
    // The number of nodes in the tree is in the range [1, 104].
    // -231 <= Node.val <= 231 - 1
    struct ValidateBST
    {
        // solves the problem using space complexity O(n)
        bool isValidBST_memory(Leet::TreeNode *root)
        {
            std::vector<int> inOrder;

            isValidBST_memory_helper(root, inOrder);

            for (int i = 1; i < inOrder.size(); i++) {
                if (inOrder[i] <= inOrder[i - 1])
                    return false;
            }

            return true;
        }

        void isValidBST_memory_helper(Leet::TreeNode *node,
                                      std::vector<int> &arr)
        {
            if (!node)
                return;

            isValidBST_memory_helper(node->left, arr);
            arr.push_back(node->val);
            isValidBST_memory_helper(node->right, arr);
        }

        // solves the problem using space complexity O(1)
        bool isValidBST(Leet::TreeNode *root)
        {
            return isValidBST_helper(root, INT_MIN - 1ll, INT_MAX + 1ll);
        }

        // think of this as a valid "range"
        bool isValidBST_helper(Leet::TreeNode *node, long long min,
                               long long max)
        {
            if (!node)
                return true;

            if (node->val > min && node->val < max) {
                return isValidBST_helper(node->left, min, node->val) &&
                       isValidBST_helper(node->right, node->val, max);
            }

            return false;
        }
    };
}  // namespace Leet::Medium