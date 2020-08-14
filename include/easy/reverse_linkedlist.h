#pragma once

#include <../listnode.h>

namespace Leet::Easy
{
    // Reverse a singly linked list.

    // Example:
    // Input: 1->2->3->4->5->NULL
    // Output: 5->4->3->2->1->NULL
    // Follow up:

    // A linked list can be reversed either iteratively or recursively. Could you implement both?
    struct ReverseLinkedList
    {
        Leet::ListNode *reverseList(Leet::ListNode *head)
        {
            Leet::ListNode *curr = head;
            Leet::ListNode *prev = nullptr;
            Leet::ListNode *temp = nullptr;

            while (curr)
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            return prev;
        }

        Leet::ListNode *reverseList_recursive(Leet::ListNode *head)
        {
            if (head == nullptr || head->next == nullptr)
                return head;

            auto curr = reverseList_recursive(head->next);

            head->next->next = head;
            head->next = nullptr;

            return curr;
        }
    };
} // namespace Leet::Easy
