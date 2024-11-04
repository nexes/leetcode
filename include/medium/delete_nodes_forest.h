#pragma once

#include <unordered_set>
#include <vector>

#include "../treenode.h"

using std::unordered_set;
using std::vector;

namespace Leet::Medium {
    // Given the root of a binary tree, each node in the tree has a distinct value.
    // After deleting all nodes with a value in to_delete, we are left with a forest (a
    // disjoint union of trees).

    // Return the roots of the trees in the remaining forest. You may return the result in
    // any order.

    // Example 1:
    // Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
    // Output: [[1,2,null,4],[6],[7]]

    // Example 2:
    // Input: root = [1,2,4,null,3], to_delete = [3]
    // Output: [[1,2,4]]

    // Constraints:
    // The number of nodes in the given tree is at most 1000.
    // Each node has a distinct value between 1 and 1000.
    // to_delete.length <= 1000
    // to_delete contains distinct values between 1 and 1000.
    struct DeleteNodesForest
    {
        TreeNode* removeNode(TreeNode* node, vector<TreeNode*>& roots,
                             unordered_set<int>& values)
        {
            if (node == nullptr)
                return nullptr;

            node->left = removeNode(node->left, roots, values);
            node->right = removeNode(node->right, roots, values);

            if (values.count(node->val) == 1) {
                if (node->left != nullptr)
                    roots.push_back(node->left);

                if (node->right != nullptr)
                    roots.push_back(node->right);

                return nullptr;
            }

            return node;
        }

        vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
        {
            vector<TreeNode*> roots;
            unordered_set<int> toDelete(to_delete.begin(), to_delete.end());

            root = removeNode(root, roots, toDelete);
            if (root != nullptr)
                roots.push_back(root);

            return roots;
        }
    };
}  // namespace Leet::Medium
