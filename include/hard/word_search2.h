#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

namespace Leet::Hard {
    // Given an m x n board of characters and a list of strings words, return all words on
    // the board. Each word must be constructed from letters of sequentially adjacent
    // cells, where adjacent cells are horizontally or vertically neighboring. The same
    // letter cell may not be used more than once in a word.

    // Example 1:
    // Input: board =
    // [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words =
    // ["oath","pea","eat","rain"] Output: ["eat","oath"]

    // Example 2:
    // Input: board = [["a","b"],["c","d"]], words = ["abcb"]
    // Output: []

    // Constraints:
    // m == board.length
    // n == board[i].length
    // 1 <= m, n <= 12
    // board[i][j] is a lowercase English letter.
    // 1 <= words.length <= 3 * 104
    // 1 <= words[i].length <= 10
    // words[i] consists of lowercase English letters.
    // All the strings of words are unique.
    class WordSearch2
    {
    private:
        enum WordType : int {
            Prefix = 0,
            Word = 1,
            None = 2,
        };

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

            void insert(string word)
            {
                TrieNode* curr = &root;

                for (char c : word) {
                    if (!curr->children.count(c))
                        curr->children[c] = TrieNode();
                    curr = &curr->children[c];
                }
                curr->isWord = true;
            }

            WordType search(string word)
            {
                TrieNode* curr = &root;

                for (int i = 0; i < word.length(); i++) {
                    if (!curr->children.count(word[i]))
                        return WordType::None;
                    curr = &curr->children[word[i]];
                }

                return curr->isWord ? WordType::Word : WordType::Prefix;
            }

            bool hasStartChar(char c)
            {
                return root.children.count(c);
            }
        };

    public:
        void searchWord(Trie& trie, vector<vector<char>>& board,
                        unordered_set<string>& words, string curr, int i, int j)
        {
            if (i < 0 || i < 0 || i >= board.size() || j >= board[0].size())
                return;
            if (board[i][j] == '!')
                return;

            char originalChar = board[i][j];
            curr.push_back(originalChar);

            WordType type = trie.search(curr);

            if (type == WordType::Word) {
                // we found a word, save it, but we will keep looking for longer words
                // with this prefix
                if (!words.count(curr)) {
                    words.insert(curr);
                }
            } else if (type == WordType::None) {
                return;
            }

            board[i][j] = '!';

            searchWord(trie, board, words, curr, i - 1, j);
            searchWord(trie, board, words, curr, i + 1, j);
            searchWord(trie, board, words, curr, i, j + 1);
            searchWord(trie, board, words, curr, i, j - 1);

            board[i][j] = originalChar;
            curr.pop_back();
        }

        vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
        {
            Trie trie;
            unordered_set<string> wordSet;

            for (string word : words)
                trie.insert(word);

            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (trie.hasStartChar(board[i][j])) {
                        searchWord(trie, board, wordSet, "", i, j);
                    }
                }
            }

            vector<string> foundWords(wordSet.begin(), wordSet.end());
            return foundWords;
        }
    };
}  // namespace Leet::Hard