#pragma once

#include <memory>
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
            auto* curr = &root;

            for (auto& c : word)
            {
                if (curr->children.find(c) == curr->children.end())
                    curr->children[c] = std::make_shared<node>();

                curr = curr->children[c].get();
            }

            curr->is_word = true;
        }

        bool search(std::string word)
        {
            auto* curr = &root;

            for (auto& c : word)
            {
                if (curr->children.find(c) == curr->children.end())
                    return false;

                curr = curr->children[c].get();
            }

            return curr->is_word;
        }

        bool startsWith(std::string prefix)
        {
            auto* curr = &root;

            for (auto& c : prefix)
            {
                if (curr->children.find(c) == curr->children.end())
                    return false;

                curr = curr->children[c].get();
            }

            return true;
        }

    private:
        struct node
        {
            node() : is_word(false), children() {}

            bool is_word;
            std::unordered_map<char, std::shared_ptr<node>> children;
        };

    private:
        node root;
    };
}  // namespace Leet::Medium
