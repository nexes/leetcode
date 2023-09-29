#pragma once

#include <algorithm>
#include <climits>
#include <vector>

#include "../listnode.h"

namespace Leet::Hard {
    // You are given an array of k linked-lists lists, each linked-list is
    // sorted in ascending order. Merge all the linked-lists into one sorted
    // linked-list and return it.

    // Example 1:
    // Input: lists = [[1,4,5],[1,3,4],[2,6]]
    // Output: [1,1,2,3,4,4,5,6]
    // Explanation: The linked-lists are:
    // [
    //   1->4->5,
    //   1->3->4,
    //   2->6
    // ]
    // merging them into one sorted list:
    // 1->1->2->3->4->4->5->6

    // Example 2:
    // Input: lists = []
    // Output: []

    // Example 3:
    // Input: lists = [[]]
    // Output: []

    // Constraints:
    // k == lists.length
    // 0 <= k <= 10^4
    // 0 <= lists[i].length <= 500
    // -10^4 <= lists[i][j] <= 10^4
    // lists[i] is sorted in ascending order.
    // The sum of lists[i].length won't exceed 10^4.
    struct MergeKList
    {
        Leet::ListNode* mergeKList(std::vector<Leet::ListNode*>& lists)
        {
            Leet::ListNode* merged = nullptr;

            for (int i = 0; i < lists.size(); i++) {
                merged = merge(merged, lists[i]);
            }

            return merged;
        }

        Leet::ListNode* merge(Leet::ListNode* list1, Leet::ListNode* list2)
        {
            Leet::ListNode* merged = new Leet::ListNode();
            Leet::ListNode* curr = merged;

            while (list1 && list2) {
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
}  // namespace Leet::Hard
