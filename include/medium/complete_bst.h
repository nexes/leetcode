#pragma once

#include <../treenode.h>

#include <queue>

namespace Leet::Medium {
    // Given a binary tree, determine if it is a complete binary tree.
    // Definition of a complete binary tree from Wikipedia:
    // In a complete binary tree every level, except possibly the last,
    // is completely filled, and all nodes in the last level are as far
    // left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

    // Example 1:
    // Input: [1,2,3,4,5,6]
    // Output: true
    // Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}),
    // and all nodes in the last level ({4, 5, 6}) are as far left as possible.

    // Example 2:
    // Input: [1,2,3,4,5,null,7]
    // Output: false
    // Explanation: The node with value 7 isn't as far left as possible.

    // Note:
    // The tree will have between 1 and 100 nodes.
    struct CompleteBST
    {
        // a "cleaner" way to do it, make sure our null node is the last node
        bool isCompleteTree_cleaner(Leet::TreeNode* root)
        {
            auto q = std::queue<Leet::TreeNode*>{};
            q.emplace(root);

            auto last_node = q.front();

            while (!q.empty()) {
                auto current = q.front();
                q.pop();

                if (!last_node && current)
                    return false;

                if (current) {
                    q.emplace(current->left);
                    q.emplace(current->right);
                }

                last_node = current;
            }

            return true;
        }

        // make sure our "gap" node is the last node
        bool isCompleteTree(Leet::TreeNode* root)
        {
            bool row_gap = false;
            auto q = std::queue<Leet::TreeNode*>{};

            q.push(root);

            while (!q.empty()) {
                int len = q.size();

                for (int i = 0; i < len; i++) {
                    auto node = q.front();
                    q.pop();

                    if (row_gap) {
                        if (node->left || node->right)
                            return false;
                        continue;
                    }

                    if (node->left && node->right) {
                        q.push(node->left);
                        q.push(node->right);

                    } else if (node->left && !node->right) {
                        q.push(node->left);
                        row_gap = true;

                    } else if (!node->left && !node->right) {
                        row_gap = true;

                    } else if (!node->left && node->right) {
                        return false;
                    }
                }
            }

            return true;
        }
    };
}  // namespace Leet::Medium
