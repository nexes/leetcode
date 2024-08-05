#pragma once

#include <stack>
#include <vector>

namespace Leet::Medium {
    // Given an array of integers temperatures represents the daily temperatures, return
    // an array answer such that answer[i] is the number of days you have to wait after
    // the ith day to get a warmer temperature. If there is no future day for which this
    // is possible, keep answer[i] == 0 instead.

    // Example 1:
    // Input: temperatures = [73,74,75,71,69,72,76,73]
    // Output: [1,1,4,2,1,1,0,0]

    // Example 2:
    // Input: temperatures = [30,40,50,60]
    // Output: [1,1,1,0]

    // Example 3:
    // Input: temperatures = [30,60,90]
    // Output: [1,1,0]

    // Constraints:
    // 1 <= temperatures.length <= 105
    // 30 <= temperatures[i] <= 100
    struct DailyTemps
    {
        // O(n)
        std::vector<int> dailyTemperatures(std::vector<int>& temps)
        {
            std::vector<int> answer(temps.size(), 0);
            std::stack<std::pair<int, int>> tempstack;

            for (int i = 0; i < temps.size(); i++) {
                while (!tempstack.empty() && tempstack.top().first < temps[i]) {
                    std::pair<int, int> t = tempstack.top();
                    tempstack.pop();

                    answer[t.second] = i - t.second;
                }
                tempstack.push({temps[i], i});
            }

            return answer;
        }

        // O(n^2)
        std::vector<int> dailyTemperatures_bruteforce(std::vector<int>& temps)
        {
            std::vector<int> answers;

            for (int i = 0; i < temps.size(); i++) {
                for (int j = i + 1; j < temps.size(); j++) {
                    if (temps[j] > temps[i]) {
                        answers[i] = (j - i);
                        break;
                    }
                }
            }
            return answers;
        }
    };
}  // namespace Leet::Medium