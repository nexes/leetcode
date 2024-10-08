#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // You are given an integer array nums. You are initially positioned at the
    // array's first index, and each element in the array represents your
    // maximum jump length at that position. Return true if you can reach the
    // last index, or false otherwise.

    // Example 1:
    // Input: nums = [2,3,1,1,4]
    // Output: true
    // Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
    // index.

    // Example 2:
    // Input: nums = [3,2,1,0,4]
    // Output: false
    // Explanation: You will always arrive at index 3 no matter what. Its
    // maximum jump length is 0, which makes it impossible to reach the last
    // index.

    // Constraints:
    // 1 <= nums.length <= 104
    // 0 <= nums[i] <= 105
    struct JumpGame
    {
        // start from the end and move the goal as you go
        bool canJump_move_goal(std::vector<int> &nums)
        {
            int goal = nums.size() - 1;

            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] + i >= goal)
                    goal = i;
            }

            return goal == 0;
        }

        // if we get to an index the out paces our jumps
        bool canJump(std::vector<int> &nums)
        {
            int len = nums.size();
            int maxJump = 0;

            for (int i = 0; i < len; i++) {
                if (i > maxJump)
                    return false;
                maxJump = std::max(maxJump, nums[i] + i);
            }

            return true;
        }
    };

}  // namespace Leet::Medium