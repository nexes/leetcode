#pragma once

#include <string>
#include <vector>

namespace Leet::Medium {

    // Given a sorted integer array without duplicates, return the summary of its ranges.

    // Example 1:
    // Input:  [0,1,2,4,5,7]
    // Output: ["0->2","4->5","7"]
    // Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.

    // Example 2:
    // Input:  [0,2,3,4,6,8,9]
    // Output: ["0","2->4","6","8->9"]
    // Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
    struct SummaryRange
    {
        std::vector<std::string> summaryRanges(std::vector<int> &nums)
        {
            std::vector<std::string> ranges;
            int l = 0;
            int r = 0;

            if (nums.empty())
                return ranges;

            for (int i = 1; i < nums.size(); i++)
            {
                // cast to long because leet code likes to do this to us =)
                if (static_cast<long>(nums[i]) - static_cast<long>(nums[i - 1]) != 1)
                {
                    if (l == r)
                        ranges.emplace_back(std::to_string(nums[l]));
                    else
                        ranges.emplace_back(std::to_string(nums[l]) +"->"+ std::to_string(nums[r]));

                    l = i;
                    r = i;
                } else {
                    r++;
                }
            }

            if (l == r)
                ranges.emplace_back(std::to_string(nums[l]));
            else
                ranges.emplace_back(std::to_string(nums[l]) +"->"+ std::to_string(nums[r]));

            return ranges;
        }
    };
}  // namespace Leet::Medium
