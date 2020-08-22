#pragma once

#include <../treendoe.h>

namespace Leet::Easy
{
    struct InvertTree
    {
        Leet::TreeNode *invertTree(Leet::TreeNode *root)
        {
            if (!root)
                return root;

            invertTree(root->left);
            invertTree(root->right);

            auto temp = root->left;
            root->left = root->right;
            root->right = temp;

            return root;
        }
    };
} // namespace Leet::Easy
