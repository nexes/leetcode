#pragma once

#include <vector>

namespace Leet {
    // Definition for a binary tree from leetcode problems
    struct Node
    {
        Node()
        {
        }

        Node(int _val) : val(_val)
        {
        }

        Node(int _val, std::vector<Node*> _children) : val(_val), children(_children)
        {
        }

        int val;
        std::vector<Node*> children;
    };
}  // namespace Leet
