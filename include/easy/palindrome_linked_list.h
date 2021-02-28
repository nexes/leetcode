#pragma once

#include <stack>

#include "../listnode.h"

namespace Leet::Easy {
    // Given a singly linked list, determine if it is a palindrome.

    // Example 1:
    // Input: 1->2
    // Output: false

    // Example 2:
    // Input: 1->2->2->1
    // Output: true

    // Follow up:
    // Could you do it in O(n) time and O(1) space?
    struct PalindromeLinkedList
    {
        // using stack, time: O(n) space: O(n)
        bool isPalindrome_stack(Leet::ListNode* head)
        {
            int count = 0;
            Leet::ListNode* temp = head;
            std::stack<Leet::ListNode*> stack{};

            while (temp) {
                stack.emplace(temp);
                temp = temp->next;
            }

            count = stack.size() / 2;

            while (count > 0) {
                auto top = stack.top();
                stack.pop();

                if (head->val != top->val)
                    return false;

                head = head->next;
                count--;
            }

            return true;
        }

        // split the linked list, time: O(n) space O(1)
        // TODO: space (1)
        // bool isPalindrome(Leet::ListNode* head)
        // {
        //     Leet::ListNode* slow = head;
        //     Leet::ListNode* fast = head;

        //     // get the last part of the list
        //     while (fast->next) {
        //         slow = slow->next;
        //         fast = fast->next->next;
        //     }

        //     // reverse the last part of the list
        //     Leet::ListNode* prev = slow;
        //     slow = slow->next;
        //     while (slow) {
        //         auto temp = slow->next;
        //         slow->next = prev;
        //         prev = slow;
        //         slow = temp;
        //     }

        //     while (head != fast) {
        //         if (head->val != fast->val)
        //             return false;
        //         head = head->next;
        //         fast = fast->next;
        //     }

        //     return true;
        // }
    };
}  // namespace Leet::Easy
