#pragma once

#include <vector>
#include <../treenode.h>

namespace Leet::Easy
{
    // Given two binary trees, write a function to check if they are the same or not.
    // Two binary trees are considered the same if they are structurally
    // identical and the nodes have the same value.

    // Example 1:
    // Input:     1         1
    //           / \       / \
    //          2   3     2   3

    //         [1,2,3],   [1,2,3]
    // Output: true

    // Example 2:
    // Input:     1         1
    //           /           \
    //          2             2

    //         [1,2],     [1,null,2]
    // Output: false

    // Example 3:
    // Input:     1         1
    //           / \       / \
    //          2   1     1   2

    //         [1,2,1],   [1,1,2]
    // Output: false
    struct SameTree
    {
        bool isSameTree_no_preorder(Leet::TreeNode *p, Leet::TreeNode *q)
        {
            if (!p && !q)
                return true;
            if (!p || !q)
                return false;
            if (p->val != q->val)
                return false;

            return isSameTree_no_preorder(p->left, q->left) && isSameTree_no_preorder(p->right, q->right);
        }

        bool isSameTree_with_preorder(Leet::TreeNode *p, Leet::TreeNode *q)
        {
            if (!p && !q)
                return true;

            std::vector<int> larr;
            std::vector<int> rarr;

            preorder(p, larr);
            preorder(q, rarr);

            return larr == rarr;
        }

        void preorder(Leet::TreeNode *p, std::vector<int> &arr)
        {
            if (!p)
            {
                // some random value to indicate NULL
                arr.push_back(99);
                return;
            }

            arr.push_back(p->val);
            preorder(p->left, arr);
            preorder(p->right, arr);
        }
    };
} // namespace Leet::Easy
