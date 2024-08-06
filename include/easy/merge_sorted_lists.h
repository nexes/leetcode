#pragma once

#include "../listnode.h"

namespace Leet::Easy {
    // Merge two sorted linked lists and return it as a new sorted list. The new list
    // should be made by splicing together the nodes of the first two lists.

    // Example:
    // Input: 1->2->4, 1->3->4
    // Output: 1->1->2->3->4->4
    struct Merge_list
    {
        ListNode *mergeTwoList_recursion(ListNode *list1, ListNode *list2)
        {
            if (list1 == nullptr)
                return list2;
            if (list2 == nullptr)
                return list1;

            if (list1->val <= list2->val) {
                list1->next = mergeTwoList_recursion(list1->next, list2);
                return list1;
            } else {
                list2->next = mergeTwoList_recursion(list2->next, list2);
                return list2;
            }
        }

        ListNode *mergeTwoList(ListNode *list1, ListNode *list2)
        {
            // the dummy node is not a pointer. This way when we return merged->next we
            // don't introduce a memory leak'
            ListNode dummy;
            ListNode *curr = &dummy;
            ListNode *merged = curr;

            while (list1 != nullptr && list2 != nullptr) {
                if (list1->val <= list2->val) {
                    curr->next = list1;
                    list1 = list1->next;
                } else {
                    curr->next = list2;
                    list2 = list2->next;
                }

                curr = curr->next;
            }

            if (list1)
                curr->next = list1;
            if (list2)
                curr->next = list2;

            return merged->next;
        }
    };
}  // namespace Leet::Easy
