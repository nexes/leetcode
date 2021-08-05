#pragma once

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

namespace Leet::Medium {
    using std::pair;
    using std::string;
    using std::vector;

    // Given a nonempty list of words, return the k most frequent elements.
    // Your answer should be sorted by frequency from highest to lowest. If two words
    // have the same frequency, then the word with the lower alphabetical order comes
    // first.

    // Example 1:
    // Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
    // Output: ["i", "love"]
    // Explanation: "i" and "love" are the two most frequent words.
    // Note that "i" comes before "love" due to a lower alphabetical order.

    // Example 2:
    // Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"],
    //        k = 4
    // Output: ["the", "is", "sunny", "day"]
    // Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    //              with the number of occurrence being 4, 3, 2 and 1 respectively.
    // Note:
    // You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    // Input words contain only lowercase letters.

    // Follow up:
    // Try to solve it in O(n log k) time and O(n) extra space.
    struct KFrequentWords
    {
        // accepted but this is the naive approach
        vector<string> topKFrequent(vector<string>& words, int k)
        {
            vector<string> kwords{};
            std::unordered_map<string, int> freq{};

            // populate our frequency map
            for (const auto& word : words) {
                if (auto ret = freq.emplace(word, 1); !ret.second) {
                    freq[word]++;
                }
            }

            // our compare function to handle lexical ordering if the freq is the same
            auto compare = [](const pair<int, string>& a, const pair<int, string>& b) {
                if (a.first == b.first) {
                    return a.second > b.second;
                }

                return a < b;
            };

            std::priority_queue<pair<int, string>, vector<pair<int, string>>,
                                decltype(compare)>
                map(compare);

            // populate our max heap
            for (const auto& [word, count] : freq) {
                map.emplace(count, word);
            }

            // populate our return vector
            for (int i = 0; i < k; i++) {
                auto word = map.top();
                map.pop();
                kwords.emplace_back(word.second);
            }

            return kwords;
        }
    };
}  // namespace Leet::Medium
