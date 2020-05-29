#pragma once

#include <../listnode.h>

namespace Leet::Medium
{

    // Given a linked list, swap every two adjacent nodes and return its head.
    // You may not modify the values in the list's nodes, only nodes itself may be changed.

    // Example:
    // Given 1->2->3->4, you should return the list as 2->1->4->3.

    // Definition for singly-linked list taken from LeetCode problem
    struct SwapNodes
    {
        // swap every pair while maintaining the original list, creating a new swapped list
        Leet::ListNode *swapPairs(Leet::ListNode *head)
        {
            if (head == nullptr || head->next == nullptr)
                return head;

            auto *swapped = new Leet::ListNode(head->next->val);
            swapped->next = new Leet::ListNode(head->val);

            auto *curr = swapped->next;
            head = head->next->next;

            while (head && head->next)
            {
                curr->next = new Leet::ListNode(head->next->val);
                curr->next->next = new Leet::ListNode(head->val);

                head = head->next->next;
                curr = curr->next->next;
            }

            return swapped;
        }

        // swap every pair, not maintaining the original list
        Leet::ListNode *swap_pairs_inplace(Leet::ListNode *head)
        {
            auto *orig_head = head;

            while (head && head->next)
            {
                std::swap(head->val, head->next->val);
                head = head->next->next;
            }

            return orig_head;
        }
    };
} // namespace Leet::Medium
