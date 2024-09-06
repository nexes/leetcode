#pragma once

#include <map>
#include <vector>

namespace Leet::Medium {
    // Alice has some number of cards and she wants to rearrange the cards into groups so
    // that each group is of size groupSize, and consists of groupSize consecutive cards.
    // Given an integer array hand where hand[i] is the value written on the ith card and
    // an integer groupSize, return true if she can rearrange the cards, or false
    // otherwise.

    // Example 1:
    // Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
    // Output: true
    // Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

    // Example 2:
    // Input: hand = [1,2,3,4,5], groupSize = 4
    // Output: false
    // Explanation: Alice's hand can not be rearranged into groups of 4.

    // Constraints:
    // 1 <= hand.length <= 104
    // 0 <= hand[i] <= 109
    // 1 <= groupSize <= hand.length

    // Note: This question is the same as 1296:
    // https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
    struct HandOfStraight
    {
        bool isNStraightHand(std::vector<int>& hand, int groupSize)
        {
            if (hand.size() % groupSize != 0)
                return false;

            std::map<int, int> freq;
            for (int h : hand)
                freq[h]++;

            while (!freq.empty()) {
                int value = freq.begin()->first;

                for (int i = 0; i < groupSize; i++) {
                    if (freq[value + i] > 0)
                        freq[value + i]--;
                    else
                        return false;

                    if (freq[value + i] == 0)
                        freq.erase(value + i);
                }
            }

            return true;
        }
    };
}  // namespace Leet::Medium