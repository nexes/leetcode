#pragma once

#include <queue>
#include <vector>

#include "../treenode.h"

namespace Leet::Medium {
    // Given the root of a binary tree, imagine yourself standing on the right side of it,
    // return the values of the nodes you can see ordered from top to bottom.

    // Example 1:
    // Input: root = [1,2,3,null,5,null,4]
    // Output: [1,3,4]

    // Example 2:
    // Input: root = [1,null,3]
    // Output: [1,3]

    // Example 3:
    // Input: root = []
    // Output: []

    // Constraints:
    // The number of nodes in the tree is in the range [0, 100].
    // -100 <= Node.val <= 100
    struct BinaryTreeRightSide
    {
        std::vector<int> rightSideView(Leet::TreeNode *root)
        {
            std::vector<int> values;
            std::queue<Leet::TreeNode *> q;

            if (root != nullptr)
                q.push(root);

            while (!q.empty()) {
                int size = q.size();

                for (int i = 0; i < size; i++) {
                    TreeNode *node = q.front();
                    q.pop();

                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);

                    // add the last node (the right most) to values
                    if (i == size - 1)
                        values.push_back(node->val);
                }
            }

            return values;
        }
    };
}  // namespace Leet::Medium