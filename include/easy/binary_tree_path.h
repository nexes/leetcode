#pragma once

#include <string>
#include <vector>

#include "../treenode.h"

namespace Leet::Easy {
    using std::string;
    using std::vector;

    // Given a binary tree, return all root-to-leaf paths.
    // Note: A leaf is a node with no children.

    // Example:
    // Input:
    //    1
    //  /   \
    // 2     3
    //  \
    //   5
    // Output: ["1->2->5", "1->3"]

    // Explanation: All root-to-leaf paths are: 1->2->5, 1->3
    struct BinaryPath
    {
        vector<string> binaryTreePaths(Leet::TreeNode* root)
        {
            vector<string> paths{};

            if (root)
                recordPath(root, "", paths);

            return paths;
        }

        void recordPath(Leet::TreeNode* node, string path, vector<string>& paths)
        {
            // check if leaf node
            if (node && !node->left && !node->right) {
                path.append(std::to_string(node->val));
                paths.emplace_back(path);
                return;
            }

            if (node->left) {
                auto p = std::to_string(node->val) + "->";
                recordPath(node->left, path + p, paths);
            }

            if (node->right) {
                auto p = std::to_string(node->val) + "->";
                recordPath(node->right, path + p, paths);
            }
        }
    };
}  // namespace Leet::Easy
