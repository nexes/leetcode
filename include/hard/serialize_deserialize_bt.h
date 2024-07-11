#pragma once

#include <stack>
#include <string>

#include "../treenode.h"

namespace Leet::Hard {
    // Serialization is the process of converting a data structure or object into a
    // sequence of bits so that it can be stored in a file or memory buffer, or
    // transmitted across a network connection link to be reconstructed later in the same
    // or another computer environment. Design an algorithm to serialize and deserialize a
    // binary tree. There is no restriction on how your serialization/deserialization
    // algorithm should work. You just need to ensure that a binary tree can be serialized
    // to a string and this string can be deserialized to the original tree structure.
    // Clarification: The input/output format is the same as how LeetCode serializes a
    // binary tree. You do not necessarily need to follow this format, so please be
    // creative and come up with different approaches yourself.

    // Example 1:
    // Input: root = [1,2,3,null,null,4,5]
    // Output: [1,2,3,null,null,4,5]

    // Example 2:
    // Input: root = []
    // Output: []

    // Constraints:
    // The number of nodes in the tree is in the range [0, 104].
    // -1000 <= Node.val <= 1000
    class Codec
    {
    private:
        void build(Leet::TreeNode *node, std::string &str, char dir)
        {
            if (node == nullptr)
                return;

            str.append(std::to_string(node->val) + dir);

            build(node->left, str, 'l');
            build(node->right, str, 'r');
            str.push_back(';');
        }

    public:
        std::string serialize(Leet::TreeNode *root)
        {
            std::string encoded = "";
            if (root != nullptr)
                build(root, encoded, 's');

            return encoded;
        }

        Leet::TreeNode *deserialize(std::string data)
        {
            if (data.empty())
                return nullptr;

            TreeNode *rtn_node = nullptr;
            std::stack<TreeNode *> nodes;
            std::string val_str = "";

            for (int i = 0; i < data.length(); i++) {
                switch (data[i]) {
                case 's':
                    nodes.push(new TreeNode(std::stoi(val_str)));
                    val_str = "";
                    break;
                case 'l':
                    nodes.top()->left = new TreeNode(std::stoi(val_str));
                    nodes.push(nodes.top()->left);
                    val_str = "";
                    break;
                case 'r':
                    nodes.top()->right = new TreeNode(std::stoi(val_str));
                    nodes.push(nodes.top()->right);
                    val_str = "";
                    break;
                case ';':
                    rtn_node = nodes.top();
                    nodes.pop();
                    break;
                default:
                    val_str.push_back(data[i]);
                    break;
                }
            }

            return rtn_node;
        }
    };
}  // namespace Leet::Hard