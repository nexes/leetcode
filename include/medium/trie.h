#pragma once

#include <string>
#include <unordered_map>

namespace Leet::Medium {
    // Implement a trie with insert, search, and startsWith methods.

    // Example:
    // Trie trie = new Trie();

    // trie.insert("apple");
    // trie.search("apple");   // returns true
    // trie.search("app");     // returns false
    // trie.startsWith("app"); // returns true
    // trie.insert("app");
    // trie.search("app");     // returns true

    // Note:
    // You may assume that all inputs are consist of lowercase letters a-z.
    // All inputs are guaranteed to be non-empty strings.
    class Trie
    {
    public:
        Trie() : root()
        {
        }

        void insert(std::string word)
        {
            TrieNode* curr = &root;

            for (char c : word) {
                if (curr->children.count(c) == 0)
                    curr->children[c] = TrieNode();

                curr = &curr->children[c];
            }

            curr->isWord = true;
        }

        bool search(std::string word)
        {
            TrieNode* curr = &root;

            for (char c : word) {
                if (curr->children.count(c) == 0)
                    return false;

                curr = &curr->children[c];
            }

            return curr->isWord;
        }

        bool startsWith(std::string prefix)
        {
            TrieNode* curr = &root;

            for (char c : prefix) {
                if (curr->children.count(c) == 0)
                    return false;

                curr = &curr->children[c];
            }

            return true;
        }

    private:
        struct TrieNode
        {
            TrieNode() : isWord(false), children()
            {
            }

            bool isWord;
            std::unordered_map<char, TrieNode> children;
        };

        TrieNode root;
    };
}  // namespace Leet::Medium
