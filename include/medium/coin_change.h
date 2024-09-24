#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // You are given coins of different denominations and a total amount of
    // money amount. Write a function to compute the fewest number of coins
    // that you need to make up that amount. If that amount of money cannot
    // be made up by any combination of the coins, return -1.
    // You may assume that you have an infinite number of each kind of coin.

    // Example 1:
    // Input: coins = [1,2,5], amount = 11
    // Output: 3
    // Explanation: 11 = 5 + 5 + 1

    // Example 2:
    // Input: coins = [2], amount = 3
    // Output: -1

    // Example 3:
    // Input: coins = [1], amount = 0
    // Output: 0

    // Example 4:
    // Input: coins = [1], amount = 1
    // Output: 1

    // Example 5:
    // Input: coins = [1], amount = 2
    // Output: 2

    // Constraints:
    // 1 <= coins.length <= 12
    // 1 <= coins[i] <= 231 - 1
    // 0 <= amount <= 104
    struct CoinChange
    {
        // ------------ RECURSIVE solution, O(2^n) TLE ---------------
        int makeChange_recursive(std::vector<int>& coins, int idx, int amount)
        {
            if (amount == 0)
                return 0;

            // if we're at the last (1st) index of coins, see if the amount left is
            // divisible by that coin. If so return the number of coins it would take
            if (idx == 0) {
                if (amount % coins[idx] == 0)
                    return amount / coins[idx];
                return 1e9;
            }

            // we can always choose not to take a coin
            int take = 1e9;
            int dontTake = makeChange_recursive(coins, idx - 1, amount);

            // we can only take a coin if it's smaller than the amount
            if (coins[idx] <= amount)
                take = makeChange_recursive(coins, idx, amount - coins[idx]) + 1;

            return std::min(take, dontTake);
        }

        int coinChange_recursive(std::vector<int>& coins, int amount)
        {
            int count = makeChange_recursive(coins, coins.size() - 1, amount);
            return count == 1e9 ? -1 : count;
        }

        // ------------- DP TOP DOWN : O(n) -----------------
        // take our recursive solution and add memoization
        int makeChange_topdown(std::vector<int>& coins,
                               std::vector<std::vector<int>>& memo, int idx, int amount)
        {
            if (amount == 0)
                return 0;

            // if we're at the last (1st) index of coins, see if the amount left is
            // divisible by that coin. If so return the number of coins it would take
            if (idx == 0) {
                if (amount % coins[idx] == 0)
                    return amount / coins[idx];
                return 1e9;
            }

            if (memo[idx][amount] != -1)
                return memo[idx][amount];

            // we can always choose not to take a coin
            int take = 1e9;
            int dontTake = makeChange_topdown(coins, memo, idx - 1, amount);

            // we can only take a coin if it's smaller than the amount
            if (coins[idx] <= amount)
                take = makeChange_topdown(coins, memo, idx, amount - coins[idx]) + 1;

            memo[idx][amount] = std::min(take, dontTake);
            return memo[idx][amount];
        }

        int coinChange_topdown(std::vector<int>& coins, int amount)
        {
            std::vector<std::vector<int>> memo(coins.size(),
                                               std::vector<int>(amount + 1, -1));

            int ans = makeChange_topdown(coins, memo, coins.size() - 1, amount);
            return ans == 1e9 ? -1 : ans;
        }

        // -------------- DP BOTTOM UP : O(n) -----------------
        int coinChange(std::vector<int>& coins, int amount)
        {
            std::vector<int> dp(amount + 1, amount + 1);
            dp[0] = 0;

            for (int i = 1; i <= amount; i++) {
                for (int j = 0; j < coins.size(); j++) {
                    if (i >= coins[j]) {
                        dp[i] = std::min(dp[i - coins[j]] + 1, dp[i]);
                    }
                }
            }

            return dp[amount] == amount + 1 ? -1 : dp[amount];
        }
    };
}  // namespace Leet::Medium
