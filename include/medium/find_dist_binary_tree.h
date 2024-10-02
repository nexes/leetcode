#pragma once

#include <queue>

#include "../treenode.h"

namespace Leet::Medium {
    // Given the root of a binary tree and two integers p and q, return the distance
    // between the nodes of value p and value q in the tree.

    // The distance between two nodes is the number of edges on the path from one to the
    // other.

    // Example 1:
    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0
    // Output: 3
    // Explanation: There are 3 edges between 5 and 0: 5-3-1-0.

    // Example 2:
    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 7
    // Output: 2
    // Explanation: There are 2 edges between 5 and 7: 5-2-7.

    // Example 3:
    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 5
    // Output: 0
    // Explanation: The distance between a node and itself is 0.

    // Constraints:
    // The number of nodes in the tree is in the range [1, 104].
    // 0 <= Node.val <= 109
    // All Node.val are unique.
    // p and q are values in the tree.
    struct FindDistBinaryTree
    {
        TreeNode* findLCA(TreeNode* root, int p, int q)
        {
            if (root == nullptr || root->val == p || root->val == q)
                return root;

            TreeNode* left = findLCA(root->left, p, q);
            TreeNode* right = findLCA(root->right, p, q);

            if (left != nullptr && right != nullptr)
                return root;

            return left != nullptr ? left : right;
        }

        int findDist_DFS(TreeNode* node, int dest)
        {
            if (node == nullptr)
                return -1;

            if (node->val == dest)
                return 0;

            int left = findDist_DFS(node->left, dest);
            if (left > -1)
                return left + 1;

            int right = findDist_DFS(node->right, dest);
            if (right > -1)
                return right + 1;

            return -1;
        }

        int findDist_BFS(TreeNode* root, int p, int q)
        {
            std::queue<std::pair<TreeNode*, int>> treeQueue;
            treeQueue.push({root, 0});

            int dist = 0;

            while (!treeQueue.empty()) {
                auto [node, level] = treeQueue.front();
                treeQueue.pop();

                if (node->val == p || node->val == q)
                    dist += level;

                if (node->left != nullptr)
                    treeQueue.push({node->left, level + 1});
                if (node->right != nullptr)
                    treeQueue.push({node->right, level + 1});
            }

            return dist;
        }

        int findDistance(TreeNode* root, int p, int q)
        {
            TreeNode* lca = findLCA(root, p, q);

            // int s1 = findDist(lca, p);
            // int s2 = findDist(lca, q);
            // return s1 + s2;
            return findDist_BFS(lca, p, q);
        }
    };
}  // namespace Leet::Medium