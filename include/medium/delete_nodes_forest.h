#pragma once

#include <algorithm>
#include <queue>
#include <vector>

#include "../treenode.h"

namespace Leet::Medium {
    // Given the root of a binary tree, each node in the tree has a distinct value.
    // After deleting all nodes with a value in to_delete, we are left with a forest
    // (a disjoint union of trees). Return the roots of the trees in the remaining forest.
    // You may return the result in any order.

    // Example 1:
    //       1
    //    /    \
    //   2      3
    //  / \    / \
    // 4   5  6   7
    // Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
    // Output: [[1,2,null,4],[6],[7]]

    // Constraints:
    // The number of nodes in the given tree is at most 1000.
    // Each node has a distinct value between 1 and 1000.
    // to_delete.length <= 1000
    // to_delete contains distinct values between 1 and 1000.
    struct DeleteNodesInForest
    {
        std::vector<Leet::TreeNode*> delNodes(Leet::TreeNode* root, std::vector<int>& to_delete)
        {
            auto node_queue = std::queue<Leet::TreeNode*>{};
            auto out = std::vector<Leet::TreeNode*>{};

            if (!root)
                return out;

            node_queue.push(root);

            // add root if not being removed
            if (std::find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end())
                out.push_back(root);

            while (!node_queue.empty()) {
                auto current = node_queue.front();
                node_queue.pop();

                if (current->left) {
                    node_queue.push(current->left);

                    if (std::find(to_delete.begin(), to_delete.end(), current->left->val) != to_delete.end())
                        current->left = nullptr;

                    else if (std::find(to_delete.begin(), to_delete.end(), current->val) != to_delete.end())
                        out.push_back(current->left);
                }
                if (current->right) {
                    node_queue.push(current->right);

                    if (std::find(to_delete.begin(), to_delete.end(), current->right->val) != to_delete.end())
                        current->right = nullptr;

                    else if (std::find(to_delete.begin(), to_delete.end(), current->val) != to_delete.end())
                        out.push_back(current->right);
                }
            }

            return out;
        }
    };
}  // namespace Leet::Medium
