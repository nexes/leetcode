#pragma once

#include <algorithm>
#include <vector>

#include "../treenode.h"

namespace Leet::Medium {
    // You are given the root of a binary search tree (BST), where the values of
    // exactly two nodes of the tree were swapped by mistake. Recover the tree
    // without changing its structure.

    // Example 1:
    // Input: root = [1,3,null,null,2]
    // Output: [3,1,null,null,2]
    // Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and
    // 3 makes the BST valid.

    // Example 2:
    // Input: root = [3,1,4,null,null,2]
    // Output: [2,1,4,null,null,3]
    // Explanation: 2 cannot be in the right subtree of 3 because 2 < 3.
    // Swapping 2 and 3 makes the BST valid.

    // Constraints:
    //     The number of nodes in the tree is in the range [2, 1000].
    //     -231 <= Node.val <= 231 - 1

    // Follow up: A solution using O(n) space is pretty straight-forward. Could
    // you devise a constant O(1) space solution?
    struct RecoverBST
    {
        // space: O(n), time: O(nlog(n))
        void recoverTree_naive(Leet::TreeNode *root)
        {
            int index = 0;
            std::vector<int> inOrder{};

            toVector(root, inOrder);

            // I don't like this sort here
            std::sort(inOrder.begin(), inOrder.end());

            buildTree(root, inOrder, index);
        }

        void toVector(Leet::TreeNode *node, std::vector<int> &arr)
        {
            if (node == nullptr)
                return;

            toVector(node->left, arr);
            arr.push_back(node->val);
            toVector(node->right, arr);
        }

        void buildTree(Leet::TreeNode *node, std::vector<int> &arr, int &idx)
        {
            if (!node)
                return;

            buildTree(node->left, arr, idx);

            node->val = arr[idx++];

            buildTree(node->right, arr, idx);
        }

        void recoverTree(Leet::TreeNode *root)
        {
        }
    };
}  // namespace Leet::Medium