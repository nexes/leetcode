#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

// CONSTRUCT a Trie data structure to find the common prefix
struct TrieNode
{
    bool isWord;
    unordered_map<char, TrieNode> children;

    TrieNode() : isWord(false), children()
    {
    }
};

struct Trie
{
    TrieNode root;

    Trie() : root()
    {
    }

    void insert(string str)
    {
        TrieNode *curr = &root;

        for (char c : str) {
            if (curr->children.count(c) == 0)
                curr->children[c] = TrieNode();

            curr = &curr->children[c];
        }

        curr->isWord = true;
    }

    string getCommonPrefix()
    {
        string prefix = "";
        commonPrefixSearch(root, prefix);

        return prefix;
    }

    void commonPrefixSearch(TrieNode &node, string &prefix)
    {
        // once we find a level that has more than one char node
        // we have split, and at the end of the *common* prefix
        if (node.children.size() > 1)
            return;

        if (node.isWord)
            return;

        for (auto &[c, nextNode] : node.children) {
            prefix.push_back(c);
            commonPrefixSearch(nextNode, prefix);
        }
    }
};

namespace Leet::Medium {
    // Write a function to find the longest common prefix string amongst an
    // array of strings. If there is no common prefix, return an empty string
    // "".

    // Example 1:
    // Input: strs = ["flower","flow","flight"]
    // Output: "fl"

    // Example 2:
    // Input: strs = ["dog","racecar","car"]
    // Output: ""
    // Explanation: There is no common prefix among the input strings.

    // Constraints:
    // 1 <= strs.length <= 200
    // 0 <= strs[i].length <= 200
    // strs[i] consists of only lowercase English letters.
    struct LongestPrefix
    {
        // using a trie data structure O(n)
        string longestCommonPrefix(vector<string> &strs)
        {
            Trie trie;

            for (string word : strs) {
                if (word.empty())
                    return "";
                trie.insert(word);
            }

            return trie.getCommonPrefix();
        }

        // O(nlog(n))
        string longestCommonPrefix_sorting(vector<string> &strs)
        {
            string prefix = "";

            // sort the words in lexigraphical order
            // if the words are sorted in this way, we just need to check to
            // first and last string to find the LCP because these two strings
            // will be the most different. So what is common between these two,
            // will be common in all others
            std::sort(strs.begin(), strs.end());

            string first = strs[0];
            string last = strs[strs.size() - 1];
            int len = std::min(first.length(), last.length());

            for (int i = 0; i < len; i++) {
                if (first[i] == last[i])
                    prefix += first[i];
                else
                    break;
            }

            return prefix;
        }
    };
}  // namespace Leet::Medium
