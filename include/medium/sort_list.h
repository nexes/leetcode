#pragma once

#include <algorithm>
#include <vector>

#include "../listnode.h"

namespace Leet::Medium {
    // Given the head of a linked list, return the list after sorting it in
    // ascending order.

    // Example 1:
    // Input: head = [4,2,1,3]
    // Output: [1,2,3,4]

    // Example 2:
    // Input: head = [-1,5,3,4,0]
    // Output: [-1,0,3,4,5]

    // Example 3:
    // Input: head = []
    // Output: []

    // Constraints:
    // The number of nodes in the list is in the range [0, 5 * 104].
    // -105 <= Node.val <= 105

    // Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
    // (i.e. constant space)?
    struct SortLinkedList
    {
        // time: O(n log(n)), space: O(n)
        Leet::ListNode *sortList_naive(Leet::ListNode *head)
        {
            auto arr = std::vector<int>{};
            auto *curr = head;

            while (curr != nullptr) {
                arr.push_back(curr->val);
                curr = curr->next;
            }

            // O(n log(n))
            std::sort(arr.begin(), arr.end());

            curr = head;
            int idx = 0;

            while (curr != nullptr) {
                curr->val = arr[idx++];
                curr = curr->next;
            }

            return head;
        }

        Leet::ListNode *sortList(Leet::ListNode *head)
        {
            return nullptr;
        }
    };
}  // namespace Leet::Medium