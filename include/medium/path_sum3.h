#pragma once

#include <unordered_map>

#include "../treenode.h"

using std::unordered_map;

namespace Leet::Medium {
    // Given the root of a binary tree and an integer targetSum, return the number of
    // paths where the sum of the values along the path equals targetSum.

    // The path does not need to start or end at the root or a leaf, but it must go
    // downwards (i.e., traveling only from parent nodes to child nodes).

    // Example 1:
    // Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
    // Output: 3
    // Explanation: The paths that sum to 8 are shown.

    // Example 2:
    // Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    // Output: 3

    // Constraints:
    // The number of nodes in the tree is in the range [0, 1000].
    // -109 <= Node.val <= 109
    // -1000 <= targetSum <= 1000
    struct PathSum3
    {
        // O(n)
        // using prefix sums with a map instead of a vector. See if we've seen the diff of
        // current and target, if we've seen that sum, then we have a range were target
        // exists.
        void sum(TreeNode* node, unordered_map<long, int>& sums, int& count, long current,
                 int target)
        {
            if (node == nullptr)
                return;

            current += node->val;

            if (current == target)
                count++;

            count += sums[current - target];

            sums[current]++;
            sum(node->left, sums, count, current, target);
            sum(node->right, sums, count, current, target);

            // remove this current sum as we backtrack away from this branch
            sums[current]--;
        }

        int pathSum(TreeNode* root, int targetSum)
        {
            int count = 0;
            unordered_map<long, int> sums;

            sum(root, sums, count, 0, targetSum);
            return count;
        }
    };
}  // namespace Leet::Medium