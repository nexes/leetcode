#pragma once

#include <queue>
#include <vector>

#include "../treenode.h"

namespace Leet::Medium {
    using std::queue;
    using std::vector;

    // Given the root of a binary tree, return the level order traversal of its nodes'
    // values. (i.e., from left to right, level by level).

    // Example 1:
    // Input: root = [3,9,20,null,null,15,7]
    // Output: [[3],[9,20],[15,7]]

    // Example 2:
    // Input: root = [1]
    // Output: [[1]]

    // Example 3:
    // Input: root = []
    // Output: []

    // Constraints:
    //     The number of nodes in the tree is in the range [0, 2000].
    //     -1000 <= Node.val <= 1000

    struct BreadthFirst
    {
        vector<vector<int>> levelOrder(Leet::TreeNode* root)
        {
            vector<vector<int>> levels{};
            queue<Leet::TreeNode*> q{};

            if (!root)
                return levels;

            q.push(root);

            while (!q.empty()) {
                int size = q.size();
                vector<int> level{};

                for (int i = 0; i < size; i++) {
                    auto node = q.front();
                    q.pop();

                    level.emplace_back(node->val);

                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }

                levels.emplace_back(level);
            }

            return levels;
        }
    };
}  // namespace Leet::Medium
