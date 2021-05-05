#pragma once

#include <queue>
#include <vector>

#include "../treenode.h"

namespace Leet::Easy {
    // Given the root of a binary tree, return the average value of the nodes on each
    // level in the form of an array. Answers within 10-5 of the actual answer will be
    // accepted.

    // Example 1:
    // Input: root = [3,9,20,null,15,7]
    // Output: [3.00000,14.50000,11.00000]
    // Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on
    // level 2 is 11. Hence return [3, 14.5, 11].

    // Example 2:
    // Input: root = [3,9,20,15,7]
    // Output: [3.00000,14.50000,11.00000]

    // Constraints:
    // The number of nodes in the tree is in the range [1, 104].
    // -231 <= Node.val <= 231 - 1
    struct AverageLevel
    {
        std::vector<double> averageOfLevels(Leet::TreeNode* root)
        {
            std::vector<double> avg{};
            std::queue<Leet::TreeNode*> level{};

            level.push(root);

            while (!level.empty()) {
                double size = level.size();
                double sum = 0;

                for (int i = 0; i < size; i++) {
                    auto child = level.front();
                    level.pop();

                    sum += child->val;

                    if (child->left)
                        level.push(child->left);
                    if (child->right)
                        level.push(child->right);
                }

                avg.emplace_back(sum / size);
            }

            return avg;
        }
    };
}  // namespace Leet::Easy
