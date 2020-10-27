#pragma onece

#include <../listnode.h>

namespace Leet::Medium {
    // You are given two non-empty linked lists representing two non-negative integers. The digits are
    // stored in reverse order and each of their nodes contain a single digit. Add the two numbers and
    // return it as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    // Example:
    // Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    // Output: 7 -> 0 -> 8
    // Explanation: 342 + 465 = 807.
    struct TwoNumbers
    {
        Leet::ListNode *addTwoNumbers(Leet::ListNode *l1, Leet::ListNode *l2)
        {
            Leet::ListNode *head = new Leet::ListNode();
            add(head, l1, l2, 0);

            return head->next;
        }

        void add(Leet::ListNode *head, Leet::ListNode *l1, Leet::ListNode *l2, int rem)
        {
            int n = rem;
            rem = 0;

            if (l1 == nullptr && l2 == nullptr) {
                if (n > 0 && n < 10) {
                    head->next = new Leet::ListNode(n);
                } else if (n >= 10) {
                    head->next = new Leet::ListNode(n % 10);
                    head->next->next = new Leet::ListNode(n / 10);
                }

                return;
            }

            if (l1)
                n += l1->val;
            if (l2)
                n += l2->val;

            if (n > 9) {
                rem = n / 10;
                n = n % 10;
            }

            head->next = new Leet::ListNode(n);

            auto *ll = l1 ? l1->next : nullptr;
            auto *rl = l2 ? l2->next : nullptr;
            add(head->next, ll, rl, rem);
        }
    };
}  // namespace Leet::Medium
