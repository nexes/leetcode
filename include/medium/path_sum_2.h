#pragma once

#include <vector>

#include "../treenode.h"

namespace Leet::Medium {
    using std::vector;

    // Given the root of a binary tree and an integer targetSum, return all root-to-leaf
    // paths where each path's sum equals targetSum. A leaf is a node with no children.

    // Example 1:
    // Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    // Output: [[5,4,11,2],[5,8,4,5]]

    // Example 2:
    // Input: root = [1,2,3], targetSum = 5
    // Output: []

    // Example 3:
    // Input: root = [1,2], targetSum = 0
    // Output: []

    // Constraints:
    //     The number of nodes in the tree is in the range [0, 5000].
    //     -1000 <= Node.val <= 1000
    //     -1000 <= targetSum <= 1000
    struct PathSum2
    {
        vector<vector<int>> pathSum(Leet::TreeNode* root, int targetSum)
        {
            vector<vector<int>> paths{};
            vector<int> curr{};

            find_path(root, 0, targetSum, curr, paths);

            return paths;
        }

        // don't pass the temp vector by reference, only the paths vector
        void find_path(Leet::TreeNode* node, int sum, int target, vector<int> curr,
                       vector<vector<int>>& paths)
        {
            if (!node)
                return;

            curr.emplace_back(node->val);

            if (!node->left && !node->right)
                if (sum + node->val == target)
                    paths.emplace_back(curr);

            find_path(node->left, sum + node->val, target, curr, paths);
            find_path(node->right, sum + node->val, target, curr, paths);
        }
    };
}  // namespace Leet::Medium
