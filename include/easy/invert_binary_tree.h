#pragma once

#include "../treenode.h"

namespace Leet::Easy {
    struct InvertTree
    {
        Leet::TreeNode *invertTree(Leet::TreeNode *root)
        {
            if (!root)
                return root;

            auto left = invertTree(root->left);
            auto right = invertTree(root->right);

            root->left = right;
            root->right = left;

            return root;
        }
    };
}  // namespace Leet::Easy
