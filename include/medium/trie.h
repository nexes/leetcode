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
            for (int i = 0; i < word.size(); i++)
            {
            }
        }

        bool search(std::string word)
        {
            return false;
        }

        bool startsWith(std::string prefix)
        {
            prefix.push_back('s');
            return false;
        }

    private:
        struct node
        {
            node() : children(), is_word(false) {}

            std::unordered_map<char, node *> children;
            bool is_word;
        };

    private:
        node root;
    };
}  // namespace Leet::Medium
