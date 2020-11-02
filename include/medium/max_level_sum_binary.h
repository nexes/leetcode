#pragma once

#include <../treenode.h>

#include <queue>

namespace Leet::Medium {
    // Given the root of a binary tree, the level of its root is 1, the level
    // of its children is 2, and so on. Return the smallest level X such that
    // the sum of all the values of nodes at level X is maximal.

    // Example 1:
    // Input: root = [1,7,0,7,-8,null,null]
    // Output: 2
    // Explanation:
    // Level 1 sum = 1.
    // Level 2 sum = 7 + 0 = 7.
    // Level 3 sum = 7 + -8 = -1.
    // So we return the level with the maximum sum which is level 2.

    // Example 2:
    // Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
    // Output: 2

    // Constraints:
    // The number of nodes in the tree is in the range [1, 104].
    // -105 <= Node.val <= 105
    struct
    {
        int maxLevelSum(Leet::TreeNode* root)
        {
            auto q = std::queue<Leet::TreeNode*>{};
            int max_level = 1;
            int max_sum = root->val;

            q.push(root->left);
            q.push(root->right);

            int temp = 0;
            int len = 0;
            int level = 1;
            while (!q.empty()) {
                len = q.size();
                temp = 0;
                level++;

                for (int i = 0; i < len; i++) {
                    auto child = q.front();
                    q.pop();

                    if (child) {
                        temp += child->val;
                        if (child->left) q.push(child->left);
                        if (child->right) q.push(child->right);
                    }
                }

                if (temp > max_sum) {
                    max_sum = temp;
                    max_level = level;
                }
            }

            return max_level;
        }
    };
}  // namespace Leet::Medium
