#pragma once

#include <algorithm>
#include <queue>

#include "../treenode.h"

namespace Leet::Easy {
    // Given a binary tree, find its minimum depth.
    // The minimum depth is the number of nodes along the shortest path from the root node
    // down to the nearest leaf node. Note: A leaf is a node with no children.

    // Example:
    // Given binary tree [3,9,20,null,null,15,7],
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    // return its minimum depth = 2
    struct MinDepthTree
    {
        int minDepth_bfs(Leet::TreeNode *root)
        {
            // track the depth of the node in the queue
            // otherwise we could use a while loop inside the main while loop to evaluate
            // the entire level and then increment the depth
            std::queue<std::pair<TreeNode *, int>> q;

            if (root == nullptr)
                return 0;

            q.push({root, 1});

            while (!q.empty()) {
                auto [node, depth] = q.front();
                q.pop();

                if (node->left == nullptr && node->right == nullptr)
                    return depth;

                if (node->left != nullptr)
                    q.push({node->left, depth + 1});

                if (node->right != nullptr)
                    q.push({node->right, depth + 1});
            }

            return 1;
        }

        // dfs
        int minDepth(Leet::TreeNode *root)
        {
            if (!root)
                return 0;

            int left = minDepth(root->left);
            int right = minDepth(root->right);

            // if both sub trees return a value, take the min, if one sub tree returned a
            // 0, meaning there is no sub tree, return the subtree that had a value
            if (left > 0 && right > 0)
                return std::min(left, right) + 1;
            return std::max(left, right) + 1;
        }
    };
}  // namespace Leet::Easy
