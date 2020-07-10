#pragma once

#include <../listnode.h>

namespace Leet::Medium
{
    // Given a linked list, remove the n-th node from the end of list and return its head.

    // Example:                 2     4
    // Given linked list: 1->2->3->4->5, and n = 2.
    // After removing the second node from the end, the linked list becomes 1->2->3->5.

    // Note:
    // Given n will always be valid.
    struct NthNode
    {
        ListNode *removeNthFromEnd(ListNode *head, int n)
        {
            if (!head)
                return nullptr;

            ListNode *current = head;
            ListNode *dummy = new ListNode(0);
            dummy->next = head;

            int size = 0;

            while (current)
            {
                current = current->next;
                size++;
            }

            size -= n;
            current = dummy;

            while (size > 0)
            {
                size--;
                current = current->next;
            }

            current->next = current->next->next;

            return dummy->next;
        }

        // O(n + m)
        ListNode *removeNthFromEnd_one_pass(ListNode *head, int n)
        {
            if (!head)
                return nullptr;

            ListNode *dummy = new ListNode(0);
            dummy->next = head;

            ListNode *ahead = dummy;
            ListNode *current = dummy;

            for (int i = 0; i < n + 1; i++)
                ahead = ahead->next;

            while (ahead)
            {
                ahead = ahead->next;
                current = current->next;
            }

            current->next = current->next->next;
            return dummy->next;
        }
    };
} // namespace Leet::Medium
