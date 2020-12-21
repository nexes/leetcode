#pragma once

#include <vector>

#include "../listnode.h"

namespace Leet::Medium {
    // You are given two non-empty linked lists representing two non-negative integers.
    // The most significant digit comes first and each of their nodes contain a single digit.
    // Add the two numbers and return it as a linked list. You may assume the two numbers
    // do not contain any leading zero, except the number 0 itself.

    // Follow up:
    // What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

    // Example:
    // Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
    // Output: 7 -> 8 -> 0 -> 7
    struct AddTwoNumberTwo
    {
        Leet::ListNode* reverseList(Leet::ListNode* node)
        {
            Leet::ListNode* prev = nullptr;
            Leet::ListNode* temp = nullptr;
            Leet::ListNode* curr = node;

            while (curr) {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            return prev;
        }

        // with reverse the input linked list
        Leet::ListNode* addTwoNumbers_reverse(Leet::ListNode* l1, Leet::ListNode* l2)
        {
            Leet::ListNode* sum_list = new Leet::ListNode();
            Leet::ListNode* sum_head = sum_list;
            int carry = 0;

            auto rev_l1 = reverseList(l1);
            auto rev_l2 = reverseList(l2);

            while (rev_l1 || rev_l2 || carry > 0) {
                auto val1 = rev_l1 ? rev_l1->val : 0;
                auto val2 = rev_l2 ? rev_l2->val : 0;

                sum_list->next = new Leet::ListNode((val1 + val2 + carry) % 10);
                carry = (val1 + val2 + carry) / 10;

                if (rev_l1) rev_l1 = rev_l1->next;
                if (rev_l2) rev_l2 = rev_l2->next;

                sum_list = sum_list->next;
            }

            return reverseList(sum_head->next);
        }

        // without revesing the input linked lists
        Leet::ListNode* addTwoNumbers(Leet::ListNode* l1, Leet::ListNode* l2)
        {
            Leet::ListNode* sum_list = new Leet::ListNode();
            Leet::ListNode* sum_head = sum_list;
            auto vec_l1 = std::vector<int>{};
            auto vec_l2 = std::vector<int>{};

            while (l1 || l2) {
                if (l1) vec_l1.push_back(l1->val);
                if (l2) vec_l2.push_back(l2->val);

                if (l1) l1 = l1->next;
                if (l2) l2 = l2->next;
            }

            int carry = 0;
            int l1_len = vec_l1.size() - 1;
            int l2_len = vec_l2.size() - 1;

            while (l1_len >= 0 || l2_len >= 0 || carry > 0) {
                int val1 = l1_len >= 0 ? vec_l1[l1_len] : 0;
                int val2 = l2_len >= 0 ? vec_l2[l2_len] : 0;

                sum_list->next = new Leet::ListNode((val1 + val2 + carry) % 10);
                carry = (val1 + val2 + carry) / 10;

                sum_list = sum_list->next;
                l1_len--;
                l2_len--;
            }

            return reverseList(sum_head->next);
        }
    };
}  // namespace Leet::Medium
