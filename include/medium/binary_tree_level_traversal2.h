#pragma once

#include <queue>
#include <vector>

#include "../treenode.h"

using std::vector;

namespace Leet::Medium {
    // Given the root of a binary tree, return the bottom-up level order traversal of its
    // nodes' values. (i.e., from left to right, level by level from leaf to root).

    // Example 1:
    // Input: root = [3,9,20,null,null,15,7]
    // Output: [[15,7],[9,20],[3]]

    // Example 2:
    // Input: root = [1]
    // Output: [[1]]

    // Example 3:
    // Input: root = []
    // Output: []

    // Constraints:
    // The number of nodes in the tree is in the range [0, 2000].
    // -1000 <= Node.val <= 1000
    struct BinaryTreeLevelOrder2
    {
        vector<vector<int>> levelOrderBottom(Leet::TreeNode *root)
        {
            vector<vector<int>> levels;
            std::queue<TreeNode *> q;

            if (root == nullptr)
                return levels;

            q.push(root);
            while (!q.empty()) {
                int len = q.size();
                vector<int> level;

                for (int i = 0; i < len; i++) {
                    TreeNode *n = q.front();
                    q.pop();

                    level.push_back(n->val);

                    if (n->left != nullptr)
                        q.push(n->left);
                    if (n->right != nullptr)
                        q.push(n->right);
                }

                levels.push_back(level);
            }

            std::reverse(levels.begin(), levels.end());
            return levels;
        }
    };
}  // namespace Leet::Medium