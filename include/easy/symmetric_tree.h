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
        // iteratively - breadth first search
        bool isSymmetric(Leet::TreeNode *root)
        {
            std::queue<Leet::TreeNode *> q;

            if (!root || !root->left && !root->right)
                return true;

            q.push(root->left);
            q.push(root->right);

            while (!q.empty()) {
                auto topl = q.front();
                q.pop();
                auto topr = q.front();
                q.pop();

                if (!topl && !topr)
                    continue;
                if (!topl || !topr)
                    return false;
                if (topl->val != topr->val)
                    return false;

                q.push(topl->left);
                q.push(topr->right);
                q.push(topl->right);
                q.push(topr->left);
            }

            return true;
        }

        // recursively
        bool isSymmetric_recursive(Leet::TreeNode *root)
        {
            return isSymmetric_recursive_helper(root, root);
        }

        bool isSymmetric_recursive_helper(Leet::TreeNode *left, Leet::TreeNode *right)
        {
            if (!left && !right)
                return true;
            if (!left || !right)
                return false;

            return (left->val == right->val) &&
                   isSymmetric_recursive_helper(left->left, right->right) &&
                   isSymmetric_recursive_helper(left->right, right->left);
        }
    };
}  // namespace Leet::Easy
