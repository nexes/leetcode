#pragma once

#include <vector>

#include "../treenode.h"

namespace Leet::Medium {
    // Given the root of a binary search tree, and an integer k, return the kth
    // smallest value (1-indexed) of all the values of the nodes in the tree.

    // Example 1:
    // Input: root = [3,1,4,null,2], k = 1
    // Output: 1

    // Example 2:
    // Input: root = [5,3,6,2,4,null,null,1], k = 3
    // Output: 3

    // Constraints:
    // The number of nodes in the tree is n.
    // 1 <= k <= n <= 104
    // 0 <= Node.val <= 104

    // Follow up: If the BST is modified often (i.e., we can do insert and
    // delete operations) and you need to find the kth smallest frequently, how
    // would you optimize?
    struct KthSmallestTree
    {
        // time: O(n)
        // space: O(1)
        int kthSmallest_linear(Leet::TreeNode *root, int k)
        {
            int k_smallest;
            dfs(root, k, k_smallest);
            return k_smallest;
        }

        void dfs(Leet::TreeNode *node, int &count, int &value)
        {
            if (node == nullptr)
                return;

            dfs(node->left, count, value);

            if (count > 0) {
                count--;
                value = node->val;
            }

            dfs(node->right, count, value);
        }

        // time: O(n)
        // space: O(n)
        int kthSmallest_with_vector(Leet::TreeNode *root, int k)
        {
            std::vector<int> inorder;

            kthSmallest_with_vector_helper(root, inorder);
            return inorder[k - 1];
        }

        void kthSmallest_with_vector_helper(Leet::TreeNode *node, std::vector<int> &nums)
        {
            if (node == nullptr)
                return;

            kthSmallest_with_vector_helper(node->left, nums);
            nums.push_back(node->val);
            kthSmallest_with_vector_helper(node->right, nums);
        }
    };
}  // namespace Leet::Medium