#pragma once

#include <iostream>

namespace Leet::Medium {

    // Given a linked list, swap every two adjacent nodes and return its head.
    // You may not modify the values in the list's nodes, only nodes itself may be changed.

    // Example:
    // Given 1->2->3->4, you should return the list as 2->1->4->3.

    // Definition for singly-linked list taken from LeetCode problem
    struct ListNode
    {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    struct SwapNodes
    {
        // swap every pair while maintaining the original list
        ListNode *swapPairs(ListNode *head)
        {
            if (head == nullptr || head->next == nullptr)
                return head;

            auto *swapped = new ListNode(head->next->val);
            swapped->next = new ListNode(head->val);

            auto *curr = swapped->next;
            head = head->next->next;

            while (head && head->next) {
                curr->next = new ListNode(head->next->val);
                curr->next->next = new ListNode(head->val);

                head = head->next->next;
                curr = curr->next->next;
            }

            return swapped;
        }

        // swap every pair, not maintaining the original list
        ListNode *swap_pairs_inplace(ListNode *head)
        {
            auto *swapped = new ListNode(0);
            swapped->next = head;

            while (head && head->next) {
                std::swap(head->val, head->next->val);
                head = head->next->next;
            }

            return swapped->next;
        }
    };
}  // namespace Leet::Medium
