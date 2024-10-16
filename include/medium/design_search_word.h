#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

namespace Leet::Medium {
    // Design a data structure that supports adding new words and finding if a string
    // matches any previously added string. Implement the WordDictionary class:

    // WordDictionary() Initializes the object.
    // void addWord(word) Adds word to the data structure, it can be matched later.
    // bool search(word) Returns true if there is any string in the data structure that
    // matches word or false otherwise. word may contain dots '.' where dots can be
    // matched with any letter.

    // Example:
    // Input
    // ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
    // [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
    // Output
    // [null,null,null,null,false,true,true,true]

    // Explanation
    // WordDictionary wordDictionary = new WordDictionary();
    // wordDictionary.addWord("bad");
    // wordDictionary.addWord("dad");
    // wordDictionary.addWord("mad");
    // wordDictionary.search("pad"); // return False
    // wordDictionary.search("bad"); // return True
    // wordDictionary.search(".ad"); // return True
    // wordDictionary.search("b.."); // return True

    // Constraints:
    // 1 <= word.length <= 25
    // word in addWord consists of lowercase English letters.
    // word in search consist of '.' or lowercase English letters.
    // There will be at most 2 dots in word for search queries.
    // At most 104 calls will be made to addWord and search.
    class WordDictionary
    {
    private:
        struct TrieNode
        {
            bool isWord;
            unordered_map<char, TrieNode> children;

            TrieNode() : isWord(false), children()
            {
            }
        };

        TrieNode root;

    public:
        WordDictionary() : root()
        {
        }

        void addWord(string word)
        {
            TrieNode* curr = &root;

            for (char c : word) {
                if (!curr->children.count(c))
                    curr->children[c] = TrieNode();
                curr = &curr->children[c];
            }

            curr->isWord = true;
        }

        bool search(string word)
        {
            TrieNode* curr = &root;
            return searchWildCard(curr, word, 0);
        }

        bool searchWildCard(TrieNode* node, string word, int idx)
        {
            if (idx == word.length())
                return node->isWord;

            for (int i = idx; i < word.length(); i++) {
                if (word[i] == '.') {
                    for (auto [_, trie] : node->children) {
                        if (searchWildCard(&trie, word, i + 1))
                            return true;
                    }
                    return false;
                }

                if (!node->children.count(word[i]))
                    return false;
                node = &node->children[word[i]];
            }

            return node->isWord;
        }
    };
}  // namespace Leet::Medium