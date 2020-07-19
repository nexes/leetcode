#pragma once

#include <../listnode.h>
#include <iostream>

namespace Leet::Easy
{
    // Given a sorted linked list, delete all duplicates such that each element appear only once

    // Example 1:
    // Input: 1->1->2
    // Output: 1->2

    // Example 2:
    // Input: 1->1->2->3->3
    // Output: 1->2->3
    struct DeleteDuplicate
    {
        Leet::ListNode *deleteDuplicates(Leet::ListNode *head)
        {
            if (!head || !head->next)
                return head;

            Leet::ListNode *dummy = new Leet::ListNode(0);
            Leet::ListNode *slow = head;
            Leet::ListNode *fast = head->next;
            dummy->next = head;

            while (fast)
            {
                if (slow->val == fast->val)
                {
                    fast = fast->next;
                }
                else
                {
                    slow->next = fast;
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            slow->next = nullptr;
            return dummy->next;
        }
    };
} // namespace Leet::Easy
