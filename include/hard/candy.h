#pragma once

#include <vector>

namespace Leet::Hard {
    // There are n children standing in a line. Each child is assigned a rating
    // value given in the integer array ratings. You are giving candies to these
    // children subjected to the following requirements:

    // Each child must have at least one candy.
    // Children with a higher rating get more candies than their neighbors.
    // Return the minimum number of candies you need to have to distribute the
    // candies to the children.

    // Example 1:
    // Input: ratings = [1,0,2]
    // Output: 5
    // Explanation: You can allocate to the first, second and third child with
    // 2, 1, 2 candies respectively.

    // Example 2:
    // Input: ratings = [1,2,2]
    // Output: 4
    // Explanation: You can allocate to the first, second and third child with
    // 1, 2, 1 candies respectively. The third child gets 1 candy because it
    // satisfies the above two conditions.

    // Constraints:
    // n == ratings.length
    // 1 <= n <= 2 * 104
    // 0 <= ratings[i] <= 2 * 104
    struct Candy
    {
        int candy(std::vector<int> &ratings)
        {
            int count = 0;
            std::vector<int> candy(ratings.size(), 1);

            // check if we are ranked higher than our left neighbor
            for (int i = 1; i < ratings.size(); i++) {
                if (ratings[i] > ratings[i - 1])
                    candy[i] = candy[i - 1] + 1;
            }

            // check if we are ranked higher than our right neighbor and
            // if we are make sure we don't already have more candy
            for (int i = ratings.size() - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
                    candy[i] = candy[i + 1] + 1;
            }

            // sum the array
            for (const int val : candy)
                count += val;

            return count;
        }
    };
}  // namespace Leet::Hard