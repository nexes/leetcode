#pragma once

#include <stack>
#include <vector>

#include "../treenode.h"

namespace Leet::Medium {
    // Given the root of a binary tree, return the inorder traversal
    // of its nodes' values.

    // Example 1:
    // Input: root = [1,null,2,3]
    // Output: [1,3,2]

    // Example 2:
    // Input: root = []
    // Output: []

    // Example 3:
    // Input: root = [1]
    // Output: [1]

    // Example 4:
    // Input: root = [1,2]
    // Output: [2,1]

    // Example 5:
    // Input: root = [1,null,2]
    // Output: [1,2]

    // Constraints:
    // The number of nodes in the tree is in the range [0, 100].
    // -100 <= Node.val <= 100

    // Follow up:
    // Recursive solution is trivial, could you do it iteratively?
    struct Inorder
    {
        // inorder without recursion.
        std::vector<int> inorderTraversal_iteratively(Leet::TreeNode* root)
        {
            std::vector<int> order{};
            std::stack<Leet::TreeNode*> stack{};

            while (root || !stack.empty()) {
                while (root) {
                    stack.push(root);
                    root = root->left;
                }
                auto curr = stack.top();
                stack.pop();

                order.push_back(curr->val);
                root = curr->right;
            }

            return order;
        }

        std::vector<int> inorderTraversal(Leet::TreeNode* root)
        {
            std::vector<int> order{};
            travers(order, root);

            return order;
        }

        void travers(std::vector<int>& order, Leet::TreeNode* node)
        {
            if (!node)
                return;

            travers(order, node->left);
            order.push_back(node->val);
            travers(order, node->right);
        }
    };
}  // namespace Leet::Medium
