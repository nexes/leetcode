#pragma once

#include <stack>

#include "../treenode.h"

using std::stack;

namespace Leet::Easy {
    // Given a binary tree and a sum, determine if the tree has a root-to-leaf path such
    // that adding up all the values along the path equals the given sum.

    // Note: A leaf is a node with no children.

    // Example:
    // Given the below binary tree and sum = 22,

    //       5
    //      / \
    //     4   8
    //    /   / \
    //   11  13  4
    //  /  \      \
    // 7    2      1
    //
    // return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

    // Definition for a binary tree node.
    struct PathSum
    {
        // O(n) using dfs
        bool findPath(TreeNode* node, int target, int current)
        {
            if (node == nullptr)
                return false;

            current += node->val;

            if (node->left == nullptr && node->right == nullptr)
                return current == target;

            bool l = findPath(node->left, target, current);
            bool r = findPath(node->right, target, current);

            return l || r;
        }

        // O(n) without recursion
        bool hasPathSum(TreeNode* root, int targetSum)
        {
            // using recursion
            // return findPath(root, targetSum, 0);

            stack<std::pair<int, TreeNode*>> treeStk;

            if (root == nullptr)
                return false;

            treeStk.push({0, root});
            while (!treeStk.empty()) {
                auto [curr, node] = treeStk.top();
                treeStk.pop();

                curr += node->val;

                if (curr == targetSum && node->left == nullptr && node->right == nullptr)
                    return true;

                if (node->left != nullptr)
                    treeStk.push({curr, node->left});
                if (node->right != nullptr)
                    treeStk.push({curr, node->right});
            }

            return false;
        }
    };

}  // namespace Leet::Easy
