#pragma once

#include <vector>

#include "../listnode.h"

namespace Leet::Medium {
    // You are given the head of a singly linked-list. The list can be represented as:

    // L0 → L1 → … → Ln - 1 → Ln
    // Reorder the list to be on the following form:

    // L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    // You may not modify the values in the list's nodes. Only nodes themselves may be
    // changed.

    // Example 1:
    // Input: head = [1,2,3,4]
    // Output: [1,4,2,3]

    // Example 2:
    // Input: head = [1,2,3,4,5]
    // Output: [1,5,2,4,3]

    // Constraints:
    // The number of nodes in the list is in the range [1, 5 * 104].
    // 1 <= Node.val <= 1000
    struct ReorderList
    {
        // time: O(n) space: O(1)
        void reorderList_merge(Leet::ListNode* head)
        {
            Leet::ListNode* mid = head;
            Leet::ListNode* fast = head;

            // get the middle node
            while (fast != nullptr && fast->next != nullptr) {
                mid = mid->next;
                fast = fast->next->next;
            }

            // reverse the linked list from the middle node on
            Leet::ListNode* prev = nullptr;
            Leet::ListNode* next = nullptr;
            Leet::ListNode* curr = mid->next;
            while (curr != nullptr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            // cut this linked list into two
            mid->next = nullptr;

            // merge the linked list from the head and tail
            while (prev != nullptr) {
                Leet::ListNode* headNext = head->next;
                Leet::ListNode* prevNext = prev->next;
                head->next = prev;
                prev->next = headNext;
                head = headNext;
                prev = prevNext;
            }
        }

        // time: O(n) space: O(n)
        void reorderList(Leet::ListNode* head)
        {
            std::vector<int> values{};

            auto curr = head;
            while (curr) {
                values.push_back(curr->val);
                curr = curr->next;
            }

            int size = values.size();

            curr = head;
            for (int i = 0, j = size - 1; i < size / 2; i++, j--) {
                curr->val = values[i];
                curr->next->val = values[j];
                curr = curr->next->next;
            }

            if (size % 2 != 0) {
                curr->val = values[size / 2];
            }
        }
    };
}  // namespace Leet::Medium
