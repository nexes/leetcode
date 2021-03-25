#pragma once

#include <../listnode.h>

#include <algorithm>

namespace Leet::Easy {
    // Write a program to find the node at which the intersection of two singly linked
    // lists begins. For example, the following two linked lists: begin to intersect at
    // node c1.

    // Example 1:
    // Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2,
    // skipB = 3 Output: Reference of the node with value = 8 Input Explanation: The
    // intersected node's value is 8 (note that this must not be 0 if the two lists
    // intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it
    // reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There
    // are 3 nodes before the intersected node in B.

    // Example 2:
    // Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
    // Output: Reference of the node with value = 2
    // Input Explanation: The intersected node's value is 2 (note that this must not be 0
    // if the two lists intersect). From the head of A, it reads as [1,9,1,2,4]. From the
    // head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A;
    // There are 1 node before the intersected node in B.

    // Example 3:
    // Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
    // Output: null
    // Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it
    // reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while
    // skipA and skipB can be arbitrary values. Explanation: The two lists do not
    // intersect, so return null.

    // Notes:
    // If the two linked lists have no intersection at all, return null.
    // The linked lists must retain their original structure after the function returns.
    // You may assume there are no cycles anywhere in the entire linked structure.
    // Each value on each linked list is in the range [1, 10^9].
    // Your code should preferably run in O(n) time and use only O(1) memory.
    struct Intersection
    {
        Leet::ListNode* getIntersectionNode(Leet::ListNode* headA, Leet::ListNode* headB)
        {
            auto a_pointer = headA;
            auto b_pointer = headB;
            int a_len = 0;
            int b_len = 0;

            while (a_pointer != nullptr) {
                a_len++;
                a_pointer = a_pointer->next;
            }

            while (b_pointer != nullptr) {
                b_len++;
                b_pointer = b_pointer->next;
            }

            a_pointer = headA;
            b_pointer = headB;

            int diff = std::abs(a_len - b_len);

            if (a_len > b_len) {
                while (diff-- > 0)
                    a_pointer = a_pointer->next;

            } else {
                while (diff-- > 0)
                    b_pointer = b_pointer->next;
            }

            while (a_pointer != b_pointer) {
                a_pointer = a_pointer->next;
                b_pointer = b_pointer->next;
            }

            return a_pointer;
        }
    };
}  // namespace Leet::Easy
