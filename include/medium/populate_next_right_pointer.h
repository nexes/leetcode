#pragma once

#include <queue>

using std::queue;

// Definition for a Node per LeetCode
namespace Populate {
    class Node
    {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL)
        {
        }

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL)
        {
        }

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next)
        {
        }
    };
}  // namespace Populate

namespace Leet::Medium {
    // You are given a perfect binary tree where all leaves are on the same level, and
    // every parent has two children. The binary tree has the following definition:

    // struct Node {
    //   int val;
    //   Node *left;
    //   Node *right;
    //   Node *next;
    // }
    // Populate each next pointer to point to its next right node. If there is no next
    // right node, the next pointer should be set to NULL.

    // Initially, all next pointers are set to NULL.

    // Example 1:
    // Input: root = [1,2,3,4,5,6,7]
    // Output: [1,#,2,3,#,4,5,6,7,#]
    // Explanation: Given the above perfect binary tree (Figure A), your function should
    // populate each next pointer to point to its next right node, just like in Figure B.
    // The serialized output is in level order as connected by the next pointers, with '#'
    // signifying the end of each level.

    // Example 2:
    // Input: root = []
    // Output: []

    // Constraints:
    // The number of nodes in the tree is in the range [0, 212 - 1].
    // -1000 <= Node.val <= 1000

    // Follow-up:
    // You may only use constant extra space.
    // The recursive approach is fine. You may assume implicit stack space does not count
    // as extra space for this problem.
    struct PopulateNextRightPointer
    {
        Populate::Node* connect(Populate::Node* root)
        {
            queue<Populate::Node*> q;

            if (root != nullptr)
                q.push(root);

            while (!q.empty()) {
                int levelSize = q.size();
                Populate::Node* prev = nullptr;

                for (int i = 0; i < levelSize; i++) {
                    Populate::Node* node = q.front();
                    q.pop();

                    if (prev != nullptr)
                        prev->next = node;
                    prev = node;

                    if (node->left != nullptr)
                        q.push(node->left);
                    if (node->right != nullptr)
                        q.push(node->right);
                }
            }

            return root;
        }
    };
}  // namespace Leet::Medium