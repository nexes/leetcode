#pragma once

#include <unordered_map>
#include <vector>

#include "../treenode.h"

namespace Leet::Easy {
    // Given a binary search tree (BST) with duplicates, find all the mode(s) (the most
    // frequently occurred element) in the given BST.

    // Assume a BST is defined as follows:
    // The left subtree of a node contains only nodes with keys less than or equal to the
    // node's key. The right subtree of a node contains only nodes with keys greater than
    // or equal to the node's key. Both the left and right subtrees must also be binary
    // search trees.

    // For example:
    // Given BST [1,null,2,2],

    //    1
    //     \
    //      2
    //     /
    //    2

    // return [2].

    // Note: If a tree has more than one mode, you can return them in any order.
    // Follow up: Could you do that without using any extra space? (Assume that the
    // implicit stack space incurred due to recursion does not count).
    struct BinaryTreeMode
    {
        std::vector<int> findMode(Leet::TreeNode* root)
        {
            std::vector<int> mode{};
            std::unordered_map<int, int> freq{};

            frequency(root, freq);

            int max = 0;
            for (const auto& [key, value] : freq) {
                if (value > max)
                    max = value;
            }

            for (const auto& [key, value] : freq) {
                if (value == max)
                    mode.emplace_back(key);
            }

            return mode;
        }

        void frequency(Leet::TreeNode* node, std::unordered_map<int, int>& map)
        {
            if (!node)
                return;

            map[node->val]++;

            frequency(node->left, map);
            frequency(node->right, map);
        }
    };
}  // namespace Leet::Easy
