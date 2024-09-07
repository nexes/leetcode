#pragma once

#include <unordered_map>
#include <vector>

#include "../listnode.h"

namespace Leet::Medium {
    // You are given an array of integers nums and the head of a linked list. Return the
    // head of the modified linked list after removing all nodes from the linked list that
    // have a value that exists in nums.

    // Example 1:
    // Input: nums = [1,2,3], head = [1,2,3,4,5]
    // Output: [4,5]
    // Explanation:
    // Remove the nodes with values 1, 2, and 3.

    // Example 2:
    // Input: nums = [1], head = [1,2,1,2,1,2]
    // Output: [2,2,2]
    // Explanation:
    // Remove the nodes with value 1.

    // Example 3:
    // Input: nums = [5], head = [1,2,3,4]
    // Output: [1,2,3,4]
    // Explanation:
    // No node has value 5.

    // Constraints:
    // 1 <= nums.length <= 105
    // 1 <= nums[i] <= 105
    // All elements in nums are unique.
    // The number of nodes in the given list is in the range [1, 105].
    // 1 <= Node.val <= 105
    // The input is generated such that there is at least one node in the linked list that
    // has a value not present in nums.
    struct DeleteNodeFromList
    {
        Leet::ListNode* modifiedList(std::vector<int>& nums, Leet::ListNode* head)
        {
            std::unordered_map<int, int> num_map;
            Leet::ListNode* new_head = head;
            Leet::ListNode* curr = head;

            for (int num : nums)
                num_map[num]++;

            while (curr != nullptr && curr->next != nullptr) {
                if (num_map.count(curr->next->val) == 1) {
                    Leet::ListNode* oldnode = curr->next;

                    curr->next = oldnode->next;
                    oldnode->next = nullptr;
                    delete oldnode;
                } else {
                    curr = curr->next;
                }
            }

            if (num_map.count(new_head->val) == 1)
                new_head = new_head->next;

            return new_head;
        }
    };
}  // namespace Leet::Medium