#pragma once

#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

namespace NaryTree {
    // N-ary tree node per leetcode
    class Node
    {
    public:
        int val;
        vector<Node*> children;

        Node()
        {
        }

        Node(int _val)
        {
            val = _val;
        }

        Node(int _val, vector<Node*> _children)
        {
            val = _val;
            children = _children;
        }
    };
}  // namespace NaryTree

namespace Leet::Medium {
    // Given a root of an N-ary tree, you need to compute the length of the diameter of
    // the tree. The diameter of an N-ary tree is the length of the longest path between
    // any two nodes in the tree. This path may or may not pass through the root.

    // (Nary-Tree input serialization is represented in their level order traversal, each
    // group of children is separated by the null value.)

    // Example 1:
    // Input: root = [1,null,3,2,4,null,5,6]
    // Output: 3
    // Explanation: Diameter is shown in red color.

    // Example 2:
    // Input: root = [1,null,2,null,3,4,null,5,null,6]
    // Output: 4

    // Example 3:
    // Input: root =
    // [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    // Output: 7

    // Constraints:
    // The depth of the n-ary tree is less than or equal to 1000.
    // The total number of nodes is between [1, 104].
    struct DiameterNaryTree
    {
        int findDiameter(NaryTree::Node* node, int& diameter)
        {
            if (node == nullptr)
                return 0;

            priority_queue<int> depths;

            for (int i = 0; i < node->children.size(); i++) {
                int depth = findDiameter(node->children[i], diameter);
                depths.push(depth);
            }

            int left = 0;
            int right = 0;

            // we may not have two paths the get so we check the heaps size both times
            if (depths.size() > 0) {
                left = depths.top();
                depths.pop();
            }
            if (depths.size() > 0) {
                right = depths.top();
                depths.pop();
            }

            diameter = std::max(diameter, left + right);
            return std::max(left, right) + 1;
        }

        int diameter(NaryTree::Node* root)
        {
            int d = 0;
            findDiameter(root, d);
            return d;
        }
    };
}  // namespace Leet::Medium