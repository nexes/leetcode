#pragma once

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

namespace Leet::Hard {
    // A transformation sequence from word beginWord to word endWord using a dictionary
    // wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    // Every adjacent pair of words differs by a single letter.
    // Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in
    // wordList. sk == endWord Given two words, beginWord and endWord, and a dictionary
    // wordList, return the number of words in the shortest transformation sequence from
    // beginWord to endWord, or 0 if no such sequence exists.

    // Example 1:
    // Input: beginWord = "hit", endWord = "cog", wordList =
    // ["hot","dot","dog","lot","log","cog"] Output: 5 Explanation: One shortest
    // transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5
    // words long.

    // Example 2:
    // Input: beginWord = "hit", endWord = "cog", wordList =
    // ["hot","dot","dog","lot","log"] Output: 0 Explanation: The endWord "cog" is not in
    // wordList, therefore there is no valid transformation sequence.

    // Constraints:
    // 1 <= beginWord.length <= 10
    // endWord.length == beginWord.length
    // 1 <= wordList.length <= 5000
    // wordList[i].length == beginWord.length
    // beginWord, endWord, and wordList[i] consist of lowercase English letters.
    // beginWord != endWord
    // All the words in wordList are unique.
    struct WordLadder
    {
        // time: O(n); n = |word1|
        // space: O(1)
        int hammingDist(string word1, string word2)
        {
            int dist = 0;
            for (int i = 0; i < word1.length(); i++)
                if (word1[i] != word2[i])
                    dist++;

            return dist;
        }

        // time: O(n^2 * m)
        // space: O()
        int ladderLength(string beginWord, string endWord, vector<string>& wordList)
        {
            vector<vector<int>> graph(wordList.size() + 1);
            int startNode = -1;
            int endNode = -1;

            // O(n) n = |wordList|
            // edge case, endWord is not found
            for (int i = 0; i < wordList.size(); i++) {
                if (wordList[i] == endWord)
                    endNode = i;
                if (wordList[i] == beginWord)
                    startNode = i;
            }

            if (endNode == -1)
                return 0;

            if (startNode == -1) {
                wordList.push_back(beginWord);
                startNode = wordList.size() - 1;
            }

            // O(n^2 * m) n = |wordList|, m = |wordList[i]|
            // build our graph
            for (int i = 0; i < wordList.size(); i++) {
                for (int j = i + 1; j < wordList.size(); j++) {
                    if (hammingDist(wordList[i], wordList[j]) == 1) {
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
                }
            }

            // O(N + E)
            // search the graph (BFS) for endWord
            // <nodeId, level>
            queue<std::pair<int, int>> graphQue;
            unordered_set<int> seen;

            graphQue.push({startNode, 1});
            seen.insert(startNode);

            while (!graphQue.empty()) {
                auto [u, level] = graphQue.front();
                graphQue.pop();

                if (u == endNode)
                    return level;

                for (int v : graph[u]) {
                    if (seen.count(v) == 0) {
                        seen.insert(v);
                        graphQue.push({v, level + 1});
                    }
                }
            }

            return 0;
        }
    };
}  // namespace Leet::Hard

// overall idea: build a graph from wordList
//
//  i. word_i is a neighbor of word_j iff hamming dist between word_i and word_j no more
//  than 1
//
// O(n)
// 0: check if endWord is in wordList. return false if false
//      0a: if beginWord != wordList, insert it in wordlist
//
// nodeID's: from 0 -> n (n == |wordList|)
// 1: build the graph (slow?? O(n^2 * m)) <--- opt,
//      1a. word1: 0 -> wordList.len
//      2a. word2: 1 -> wordList.len
//      3a. if hamming dist between word1 and word2 == 1
//          3.b word1 and word2 are neighbors
//
// O(E + V)
// 2: the graph has unweighted edges so BFS to find the path. (should be the shortest).