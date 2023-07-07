#pragma once

#include <vector>

namespace Leet::Hard {
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