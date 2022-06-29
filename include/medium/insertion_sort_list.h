#pragma once

#include "../listnode.h"

namespace Leet::Medium {
    // Given the head of a singly linked list, sort the list using insertion
    // sort, and return the sorted list's head.

    // The steps of the insertion sort algorithm:

    // Insertion sort iterates, consuming one input element each repetition and
    // growing a sorted output list.
    // At each iteration, insertion sort removes one element from the input
    // data, finds the location it belongs within the sorted list and inserts it
    // there.
    // It repeats until no input elements remain.

    // Example 1:
    // Input: head = [4,2,1,3]
    // Output: [1,2,3,4]

    // Example 2:
    // Input: head = [-1,5,3,4,0]
    // Output: [-1,0,3,4,5]

    // Constraints:
    // The number of nodes in the list is in the range [1, 5000].
    // -5000 <= Node.val <= 5000
    struct InsertionSortList
    {
        Leet::ListNode *insertionSortList(Leet::ListNode *head)
        {
            if (head == nullptr)
                return head;

            Leet::ListNode *runner;
            Leet::ListNode *curr = head->next;

            while (curr) {
                runner = head;

                while (runner && runner != curr) {
                    if (runner->val > curr->val) {
                        int temp = runner->val;
                        runner->val = curr->val;
                        curr->val = temp;
                    }

                    runner = runner->next;
                }

                curr = curr->next;
            }

            return head;
        }
    };
}  // namespace Leet::Medium