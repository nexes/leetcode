#pragma once

#include <../listnode.h>

namespace Leet::Medium {
    // You are given two non-empty linked lists representing two non-negative integers.
    // The digits are stored in reverse order, and each of their nodes contains a single
    // digit. Add the two numbers and return the sum as a linked list. You may assume the
    // two numbers do not contain any leading zero, except the number 0 itself.

    // Example 1:
    // Input: l1 = [2,4,3], l2 = [5,6,4]
    // Output: [7,0,8]
    // Explanation: 342 + 465 = 807.

    // Example 2:
    // Input: l1 = [0], l2 = [0]
    // Output: [0]

    // Example 3:
    // Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    // Output: [8,9,9,9,0,0,0,1]

    // Constraints:
    // The number of nodes in each linked list is in the range [1, 100].
    // 0 <= Node.val <= 9
    // It is guaranteed that the list represents a number that does not have leading
    // zeros.
    struct TwoNumbers
    {
        Leet::ListNode *addTwoNumbers(Leet::ListNode *l1, Leet::ListNode *l2)
        {
            ListNode dummy;
            ListNode *head = &dummy;
            ListNode *curr = &dummy;
            int carry = 0;

            while (l1 != nullptr || l2 != nullptr) {
                int lhs = l1 != nullptr ? l1->val : 0;
                int rhs = l2 != nullptr ? l2->val : 0;
                int sum = lhs + rhs + carry;
                carry = 0;

                if (sum > 9) {
                    carry = 1;
                    sum = sum % 10;
                }

                curr->next = new ListNode(sum);
                curr = curr->next;

                if (l1 != nullptr)
                    l1 = l1->next;
                if (l2 != nullptr)
                    l2 = l2->next;
            }

            if (carry > 0)
                curr->next = new ListNode(1);

            return head->next;
        }
    };
}  // namespace Leet::Medium
