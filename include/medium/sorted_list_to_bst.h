#pragma once

#include "../listnode.h"
#include "../treenode.h"

namespace Leet::Medium {
    // Given the head of a singly linked list where elements are sorted in ascending
    // order, convert it to a height-balanced
    // binary search tree.

    // Example 1:
    // Input: head = [-10,-3,0,5,9]
    // Output: [0,-3,9,-10,null,5]
    // Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown
    // height balanced BST.

    // Example 2:
    // Input: head = []
    // Output: []

    // Constraints:
    // The number of nodes in head is in the range [0, 2 * 104].
    // -105 <= Node.val <= 105
    struct ListToBST
    {
        Leet::TreeNode *buildTree(Leet::ListNode *left, Leet::ListNode *right)
        {
            if (left == right)
                return nullptr;

            ListNode *slow = left;
            ListNode *fast = left;

            while (fast != right && fast->next != right) {
                slow = slow->next;
                fast = fast->next->next;
            }

            Leet::TreeNode *root = new Leet::TreeNode(slow->val);
            root->left = buildTree(left, slow);
            root->right = buildTree(slow->next, right);
            return root;
        }

        Leet::TreeNode *sortedListToBST(Leet::ListNode *head)
        {
            return buildTree(head, nullptr);
        }
    };
}  // namespace Leet::Medium