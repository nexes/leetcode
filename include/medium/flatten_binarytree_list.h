#pragma once

#include <vector>

#include "../treenode.h"

namespace Leet::Medium {
    // Given the root of a binary tree, flatten the tree into a "linked list":
    // The "linked list" should use the same TreeNode class where the right child
    // pointer points to the next node in the list and the left child pointer is always null.
    // The "linked list" should be in the same order as a pre-order traversal of the binary tree.

    // Example 1:
    // Input: root = [1,2,5,3,4,null,6]
    // Output: [1,null,2,null,3,null,4,null,5,null,6]

    // Example 2:
    // Input: root = []
    // Output: []

    // Example 3:
    // Input: root = [0]
    // Output: [0]

    // Constraints:
    // The number of nodes in the tree is in the range [0, 2000].
    // -100 <= Node.val <= 100

    // Follow up: Can you flatten the tree in-place (with O(1) extra space)?
    struct FlattenBinaryTree
    {
        // time: O(n) space: O(n)
        void flatten_vector(Leet::TreeNode* root)
        {
            std::vector<int> values{};

            if (!root)
                return;

            helper(root, values);

            auto curr = root;
            for (int i = 0; i < values.size() - 1; i++) {
                curr->val = values[i];
                curr->left = nullptr;

                if (!curr->right)
                    curr->right = new Leet::TreeNode();

                curr = curr->right;
            }

            curr->val = values[values.size() - 1];
        }

        void helper(Leet::TreeNode* node, std::vector<int>& values)
        {
            if (!node)
                return;

            values.push_back(node->val);
            helper(node->left, values);
            helper(node->right, values);
        }

        void flatten(Leet::TreeNode* root)
        {
        }
    };
}  // namespace Leet::Medium
