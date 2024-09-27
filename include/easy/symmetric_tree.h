#pragma once

#include <queue>

#include "../treenode.h"

namespace Leet::Easy {
    // Given a binary tree, check whether it is a mirror
    // of itself (ie, symmetric around its center).

    // For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    //     1
    //    / \
    //   2   2
    //  / \ / \
    // 3  4 4  3

    // But the following [1,2,2,null,3,null,3] is not:
    //     1
    //    / \
    //   2   2
    //    \   \
    //    3    3

    // Follow up: Solve it both recursively and iteratively.
    struct SymmetricTree
    {
        bool checkSubTree(TreeNode* left, TreeNode* right)
        {
            if (left == nullptr && right == nullptr)
                return true;
            if (left == nullptr || right == nullptr)
                return false;

            bool lcheck = checkSubTree(left->left, right->right);
            bool rcheck = checkSubTree(left->right, right->left);

            return lcheck && rcheck && left->val == right->val;
        }

        bool isSymmetric_recursive(TreeNode* root)
        {
            return checkSubTree(root->left, root->right);
        }

        bool isSymmetric(TreeNode* root)
        {
            std::queue<TreeNode*> lq;
            std::queue<TreeNode*> rq;

            lq.push(root->left);
            rq.push(root->right);

            while (!lq.empty()) {
                TreeNode* lnode = lq.front();
                TreeNode* rnode = rq.front();
                lq.pop();
                rq.pop();

                if (lnode == nullptr && rnode == nullptr)
                    continue;

                if (lnode == nullptr || rnode == nullptr || lnode->val != rnode->val)
                    return false;

                lq.push(lnode->left);
                lq.push(lnode->right);

                rq.push(rnode->right);
                rq.push(rnode->left);
            }

            return true;
        }
    };
}  // namespace Leet::Easy
