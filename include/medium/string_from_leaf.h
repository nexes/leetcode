#pragma once

#include <string>

#include "../treenode.h"

namespace Leet::Medium {
    // You are given the root of a binary tree where each node has a value in the range
    // [0, 25] representing the letters 'a' to 'z'. Return the lexicographically smallest
    // string that starts at a leaf of this tree and ends at the root. As a reminder, any
    // shorter prefix of a string is lexicographically smaller. For example, "ab" is
    // lexicographically smaller than "aba". A leaf of a node is a node that has no
    // children.

    // Example 1:
    // Input: root = [0,1,2,3,4,3,4]
    // Output: "dba"

    // Example 2:
    // Input: root = [25,1,3,1,3,0,2]
    // Output: "adz"

    // Example 3:
    // Input: root = [2,2,1,null,1,0,null,0]
    // Output: "abc"

    // Constraints:
    // The number of nodes in the tree is in the range [1, 8500].
    // 0 <= Node.val <= 25
    struct SmallestStringLeaf
    {
        std::string smallestFromLeaf(Leet::TreeNode *root)
        {
            std::string smallest = "";
            helper(root, "", smallest);

            return smallest;
        }

        // O(n + m)
        void helper(Leet::TreeNode *node, std::string path, std::string &smallest)
        {
            if (node == nullptr)
                return;

            path.push_back(node->val + 'a');
            helper(node->left, path, smallest);
            helper(node->right, path, smallest);

            // is this a leaf node
            if (node->left == nullptr && node->right == nullptr) {
                std::reverse(path.begin(), path.end());

                if (!smallest.empty())
                    smallest = std::min(path, smallest);
                else
                    smallest = path;
            }
        }
    };
}  // namespace Leet::Medium