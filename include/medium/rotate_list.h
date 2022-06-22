#pragma once

#include <vector>

#include "../listnode.h"

namespace Leet::Medium {
    // Given the head of a linked list, rotate the list to the right by k
    // places.

    // Example 1:
    // Input: head = [1,2,3,4,5], k = 2
    // Output: [4,5,1,2,3]

    // Example 2:
    // Input: head = [0,1,2], k = 4
    // Output: [2,0,1]

    // Constraints:
    // The number of nodes in the list is in the range [0, 500].
    // -100 <= Node.val <= 100
    // 0 <= k <= 2 * 109
    struct RotateLlist
    {
        void reverse_vector(std::vector<int>& arr, int l, int r)
        {
            int swap;

            for (int i = l; i < r; i++, r--) {
                swap = arr[i];
                arr[i] = arr[r];
                arr[r] = swap;
            }
        }

        // we're going to use a vector which is 'cheating' a little bit
        Leet::ListNode* rotateRight_vector(Leet::ListNode* head, int k)
        {
            int i = 0;
            int size = 0;
            std::vector<int> buf;
            Leet::ListNode* curr = head;

            if (head == nullptr)
                return nullptr;

            if (k == 0)
                return head;

            // O(n)
            while (curr) {
                buf.push_back(curr->val);
                curr = curr->next;
                size++;
            }

            k = k % size;

            // O(n) rotate the array
            reverse_vector(buf, 0, size - 1);
            reverse_vector(buf, 0, k - 1);
            reverse_vector(buf, k, size - 1);

            // O(n)
            curr = head;
            while (curr) {
                curr->val = buf[i++];
                curr = curr->next;
            }

            return head;
        }

        // rotate a linked list without using a vector
        Leet::ListNode* rotateRight(Leet::ListNode* head, int k)
        {
            int i = 0;
            int diff = 0;
            int length = 1;
            Leet::ListNode* curr = head;
            Leet::ListNode* newHead = head;

            while (curr && curr->next) {
                curr = curr->next;
                length++;
            }

            k = k % length;
            diff = length - k;
            curr = head;

            if (head == nullptr || k == 0 || length == 1)
                return head;

            while (i++ < diff - 1)
                curr = curr->next;

            newHead = curr->next;
            curr->next = nullptr;
            curr = newHead;

            i = 0;
            while (i++ < k - 1)
                curr = curr->next;

            curr->next = head;

            return newHead;
        }
    };
}  // namespace Leet::Medium