#pragma once

#include "../listnode.h"

namespace Leet::Medium {
    // Given the head of a linked list, remove the nth node from the end of the list and
    // return its head.

    // Example 1:
    // Input: head = [1,2,3,4,5], n = 2
    // Output: [1,2,3,5]

    // Example 2:
    // Input: head = [1], n = 1
    // Output: []

    // Example 3:
    // Input: head = [1,2], n = 1
    // Output: [1]

    // Constraints:
    // The number of nodes in the list is sz.
    // 1 <= sz <= 30
    // 0 <= Node.val <= 100
    // 1 <= n <= sz

    // Follow up: Could you do this in one pass?
    struct RemoveNthLinkedList
    {
        Leet::ListNode *removeNthFromEnd(Leet::ListNode *head, int n)
        {
            Leet::ListNode *fast = head;
            Leet::ListNode *slow = head;

            while (fast->next != nullptr) {
                if (n-- <= 0)
                    slow = slow->next;
                fast = fast->next;
            }

            if (slow->next == nullptr)
                return slow->next;

            if (n > 0)
                return head->next;

            slow->next = slow->next->next;
            return head;
        }
    };
}  // namespace Leet::Medium