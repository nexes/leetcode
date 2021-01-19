#pragma once

#include <cmath>
#include <queue>

#include "../treenode.h"

namespace Leet::Medium {
    // Given the root of a complete binary tree, return the number of the
    //nodes in the tree. According to Wikipedia, every level, except possibly
    // the last, is completely filled in a complete binary tree, and all
    // nodes in the last level are as far left as possible. It can have between
    // 1 and 2h nodes inclusive at the last level h.

    //        1
    //      /   \
    //     2     3
    //    / \   /
    //   4   5 6

    // Example 1:
    // Input: root = [1,2,3,4,5,6]
    // Output: 6

    // Example 2:
    // Input: root = []
    // Output: 0

    // Example 3:
    // Input: root = [1]
    // Output: 1

    // Constraints:
    // The number of nodes in the tree is in the range [0, 5 * 104].
    // 0 <= Node.val <= 5 * 104
    // The tree is guaranteed to be complete.

    // Follow up: Traversing the tree to count the number of nodes in the tree
    // is an easy solution but with O(n) complexity. Could you find a faster algorithm?
    struct CountNodes
    {
        // BFS time: O(n) space: O(n)
        int countNodes(Leet::TreeNode* root)
        {
            int count = 0;
            std::queue<Leet::TreeNode*> children{};

            if (!root)
                return 0;

            children.push(root);

            while (!children.empty()) {
                int node_count = children.size();
                count += node_count;

                for (int i = 0; i < node_count; i++) {
                    auto top = children.front();
                    children.pop();

                    if (top->left)
                        children.push(top->left);
                    if (top->right)
                        children.push(top->right);
                }
            }

            return count;
        }

        // DFS time: O(n) space: O(1)
        int countNodes(Leet::TreeNode* root)
        {
            if (!root)
                return 0;

            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    };
}  // namespace Leet::Medium
