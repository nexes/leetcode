#pragma once

#include <../listnode.h>

namespace Leet::Medium
{
    // Reverse a linked list from position m to n. Do it in one-pass.
    // Note: 1 ≤ m ≤ n ≤ length of list.

    // Example:
    // Input: 1->2->3->4->5->NULL, m = 2, n = 4
    // Output: 1->4->3->2->5->NULL
    struct ReverseLinkedList2
    {
        Leet::ListNode *reverseBetween(Leet::ListNode *head, int m, int n)
        {
            if (!head)
                return head;

            Leet::ListNode *left = nullptr;
            Leet::ListNode *right = head;

            while (m > 1)
            {
                left = right;
                right = right->next;
                m--;
                n--;
            }

            auto *connect = left;
            auto *to_tail = right;

            while (n > 0)
            {
                auto *next_node = right->next;

                right->next = left;
                left = right;
                right = next_node;
                n--;
            }

            if (connect)
                connect->next = left;
            else
                head = left;

            to_tail->next = right;
            return head
        }
    };
} // namespace Leet::Medium
