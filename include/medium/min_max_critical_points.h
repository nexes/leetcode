#pragma once

#include <vector>

#include "../listnode.h"

namespace Leet::Medium {
    // A critical point in a linked list is defined as either a local maxima or a local
    // minima. A node is a local maxima if the current node has a value strictly greater
    // than the previous node and the next node. A node is a local minima if the current
    // node has a value strictly smaller than the previous node and the next node. Note
    // that a node can only be a local maxima/minima if there exists both a previous node
    // and a next node.

    // Given a linked list head, return an array of length 2 containing [minDistance,
    // maxDistance] where minDistance is the minimum distance between any two distinct
    // critical points and maxDistance is the maximum distance between any two distinct
    // critical points. If there are fewer than two critical points, return [-1, -1].

    // Example 1:
    // Input: head = [3,1]
    // Output: [-1,-1]
    // Explanation: There are no critical points in [3,1].

    // Example 2:
    // Input: head = [5,3,1,2,5,1,2]
    // Output: [1,3]
    // Explanation: There are three critical points:
    // - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
    // - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2
    // and 1.
    // - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
    // The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5
    // = 1. The maximum distance is between the third and the sixth node. maxDistance = 6
    // - 3 = 3.

    // Example 3:
    // Input: head = [1,3,2,2,3,2,2,2,7]
    // Output: [3,3]
    // Explanation: There are two critical points:
    // - [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than
    // 1 and 2.
    // - [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2
    // and 2. Both the minimum and maximum distances are between the second and the fifth
    // node. Thus, minDistance and maxDistance is 5 - 2 = 3. Note that the last node is
    // not considered a local maxima because it does not have a next node.

    // Constraints:
    // The number of nodes in the list is in the range [2, 105].
    // 1 <= Node.val <= 105
    struct MinMaxCriticalPoint
    {
        // time: O(m + nlog(n))
        // space: O(m)
        std::vector<int> nodesBetweenCriticalPoints(Leet::ListNode *head)
        {
            int l;
            int m;
            int r;
            int idx = 1;
            std::vector<int> indices;
            std::vector<int> minmax{-1, -1};

            // O(m)
            while (head != nullptr) {
                switch (idx) {
                case 1:
                    l = head->val;
                    break;
                case 2:
                    m = head->val;
                    break;
                case 3:
                    r = head->val;
                    if ((m < l && m < r) || (m > l && m > r))
                        indices.push_back(idx);
                    break;
                default:
                    l = m;
                    m = r;
                    r = head->val;
                    if ((m < l && m < r) || (m > l && m > r))
                        indices.push_back(idx);
                    break;
                }

                head = head->next;
                idx++;
            }

            // O(nlog(n))
            if (indices.size() > 1) {
                sort(indices.begin(), indices.end());
                minmax[1] = indices[indices.size() - 1] - indices[0];
                minmax[0] = minmax[1];

                for (int i = 1; i < indices.size(); i++)
                    minmax[0] = std::min(minmax[0], indices[i] - indices[i - 1]);
            }

            return minmax;
        }
    };
}  // namespace Leet::Medium