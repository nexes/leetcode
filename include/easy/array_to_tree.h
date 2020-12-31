#pragma once

#include <vector>

#include "../treenode.h"

namespace Leet::Easy {
    // Given an array where elements are sorted in ascending order, convert it
    // to a height balanced BST. For this problem, a height-balanced binary
    // tree is defined as a binary tree in which the depth of the two subtrees
    // of every node never differ by more than 1.

    // Example:
    // Given the sorted array: [-10,-3,0,5,9],
    // One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

    //       0
    //      / \
    //    -3   9
    //    /   /
    //  -10  5
    struct ArrayToTree
    {
        Leet::TreeNode* sortedArrayToBST(std::vector<int>& nums)
        {
            if (nums.empty())
                return nullptr;

            return createNode(nums, 0, nums.size());
        }

        Leet::TreeNode* createNode(std::vector<int>& nums, int low, int high)
        {
            if (low > high)
                return nullptr;

            int mid = (high + low) / 2;
            auto node = new Leet::TreeNode(nums[mid]);

            node->left = createNode(nums, low, mid - 1);
            node->right = createNode(nums, mid + 1, high);

            return node;
        }
    };
}  // namespace Leet::Easy
