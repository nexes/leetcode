#pragma once

#include "../listnode.h"

namespace Leet::Easy {
    // Remove all elements from a linked list of integers that have value val.

    // Example:
    // Input:  1->2->6->3->4->5->6, val = 6
    // Output: 1->2->3->4->5
    struct RemoveListNodes
    {
        Leet::ListNode* removeElements(Leet::ListNode* head, int val)
        {
            auto new_list = new Leet::ListNode();
            auto curr = new_list;

            while (head) {
                if (head->val != val) {
                    curr->next = new Leet::ListNode(head->val);
                    curr = curr->next;
                }
                head = head->next;
            }

            return new_list->next;
        }

        Leet::ListNode* removeElements_no_allocation(Leet::ListNode* head, int val)
        {
            auto curr = head;

            while (curr) {
                if (curr->next && curr->next->val == val)
                    curr->next = curr->next->next;
                else
                    curr = curr->next;
            }

            if (head && head->val == val)
                head = head->next;

            return head;
        }
    };
}  // namespace Leet::Easy
