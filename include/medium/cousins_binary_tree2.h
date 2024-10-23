#pragma once

#include <queue>
#include <unordered_map>

#include "../treenode.h"

namespace Leet::Medium {
    // Given the root of a binary tree, replace the value of each node in the tree with
    // the sum of all its cousins' values. Two nodes of a binary tree are cousins if they
    // have the same depth with different parents. Return the root of the modified tree.

    // Note that the depth of a node is the number of edges in the path from the root node
    // to it.

    // Example 1:
    // Input: root = [5,4,9,1,10,null,7]
    // Output: [0,0,0,7,7,null,11]
    // Explanation: The diagram above shows the initial binary tree and the binary tree
    // after changing the value of each node.
    // - Node with value 5 does not have any cousins so its sum is 0.
    // - Node with value 4 does not have any cousins so its sum is 0.
    // - Node with value 9 does not have any cousins so its sum is 0.
    // - Node with value 1 has a cousin with value 7 so its sum is 7.
    // - Node with value 10 has a cousin with value 7 so its sum is 7.
    // - Node with value 7 has cousins with values 1 and 10 so its sum is 11.

    // Example 2:
    // Input: root = [3,1,2]
    // Output: [0,0,0]
    // Explanation: The diagram above shows the initial binary tree and the binary tree
    // after changing the value of each node.
    // - Node with value 3 does not have any cousins so its sum is 0.
    // - Node with value 1 does not have any cousins so its sum is 0.
    // - Node with value 2 does not have any cousins so its sum is 0.

    // Constraints:
    // The number of nodes in the tree is in the range [1, 105].
    // 1 <= Node.val <= 104
    struct CousinBinaryTree2
    {
        TreeNode* replaceValueInTree(TreeNode* root)
        {
            std::unordered_map<int, int> levelSum;
            std::queue<TreeNode*> treeQueue;
            treeQueue.push(root);

            int level = 0;
            while (!treeQueue.empty()) {
                int levelSize = treeQueue.size();

                for (int i = 0; i < levelSize; i++) {
                    TreeNode* node = treeQueue.front();
                    treeQueue.pop();

                    levelSum[level] += node->val;

                    if (node->left != nullptr)
                        treeQueue.push(node->left);
                    if (node->right != nullptr)
                        treeQueue.push(node->right);
                }
                level++;
            }

            std::queue<std::pair<TreeNode*, int>> sibQueue;
            sibQueue.push({root, root->val});

            level = 0;
            while (!sibQueue.empty()) {
                int levelSize = sibQueue.size();

                for (int i = 0; i < levelSize; i++) {
                    auto [node, sibSum] = sibQueue.front();
                    sibQueue.pop();

                    node->val = levelSum[level] - sibSum;

                    int lChild = node->left == nullptr ? 0 : node->left->val;
                    int rChild = node->right == nullptr ? 0 : node->right->val;

                    if (node->left != nullptr)
                        sibQueue.push({node->left, lChild + rChild});
                    if (node->right != nullptr)
                        sibQueue.push({node->right, lChild + rChild});
                }
                level++;
            }

            return root;
        }
    };
}  // namespace Leet::Medium