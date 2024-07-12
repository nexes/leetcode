#pragma once

#include <unordered_map>
#include <vector>

#include "../treenode.h"

namespace Leet::Medium {
    // Given two integer arrays preorder and inorder where preorder is the preorder
    // traversal of a binary tree and inorder is the inorder traversal of the same tree,
    // construct and return the binary tree.

    // Example 1:
    // Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    // Output: [3,9,20,null,null,15,7]

    // Example 2:
    // Input: preorder = [-1], inorder = [-1]
    // Output: [-1]

    // Constraints:
    // 1 <= preorder.length <= 3000
    // inorder.length == preorder.length
    // -3000 <= preorder[i], inorder[i] <= 3000
    // preorder and inorder consist of unique values.
    // Each value of inorder also appears in preorder.
    // preorder is guaranteed to be the preorder traversal of the tree.
    // inorder is guaranteed to be the inorder traversal of the tree.
    struct BinaryTreeFromPreorder
    {
        Leet::TreeNode *helper(std::vector<int> &preorder,
                               std::unordered_map<int, int> &indices, int &index, int low,
                               int high)
        {
            if (low > high)
                return nullptr;

            Leet::TreeNode *node = new Leet::TreeNode(preorder[index++]);
            int mid = indices[node->val];

            node->left = helper(preorder, indices, index, low, mid - 1);
            node->right = helper(preorder, indices, index, mid + 1, high);

            return node;
        }

        Leet::TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
        {
            if (preorder.empty() || inorder.empty())
                return nullptr;

            int index = 0;
            std::unordered_map<int, int> indices;

            for (int i = 0; i < inorder.size(); i++)
                indices[inorder[i]] = i;

            return helper(preorder, indices, index, 0, inorder.size() - 1);
        }
    };
}  // namespace Leet::Medium