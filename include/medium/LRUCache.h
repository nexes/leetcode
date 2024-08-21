#pragma once

#include <unordered_map>

namespace Leet::Medium {
    // LRU node (double linked list)
    struct LRUNode
    {
        int key;
        int value;
        LRUNode *next;
        LRUNode *prev;

        LRUNode(int _key, int _value)
            : key(_key), value(_value), next(nullptr), prev(nullptr)
        {
        }
    };
    // Design and implement a data structure for Least Recently Used (LRU) cache.
    // It should support the following operations: get and put.
    //
    // get(key) - Get the value (will always be positive) of the key if the key exists
    // in the cache, otherwise return -1.
    //
    // put(key, value) - Set or insert the value if the key is not already present.
    // When the cache reached its capacity, it should invalidate the least recently
    // used item before inserting a new item. The cache is initialized with a positive
    // capacity.
    //
    // Follow up:
    // Could you do both operations in O(1) time complexity?
    //
    // Example:
    // LRUCache cache = new LRUCache( 2 /* capacity */ );
    //
    // cache.put(1, 1);
    // cache.put(2, 2);
    // cache.get(1);       // returns 1
    // cache.put(3, 3);    // evicts key 2
    // cache.get(2);       // returns -1 (not found)
    // cache.put(4, 4);    // evicts key 1
    // cache.get(1);       // returns -1 (not found)
    // cache.get(3);       // returns 3
    // cache.get(4);       // returns 4
    class LRUCache
    {
    public:
        LRUCache(int capacity)
            : capacity(capacity),
              head(new LRUNode(-1, -1)),
              tail(new LRUNode(-1, -1)),
              indices()
        {
            head->next = tail;
            tail->prev = head;
        }

        int get(int key)
        {
            int value = -1;

            if (this->indices.count(key) == 1) {
                LRUNode *curr = this->indices[key];
                value = curr->value;

                // move the node to the head of the list
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr->prev = head;
                curr->next = head->next;

                head->next->prev = curr;
                head->next = curr;
            }

            return value;
        }

        void put(int key, int value)
        {
            if (this->indices.count(key) == 0) {
                LRUNode *node = new LRUNode(key, value);
                node->prev = head;
                node->next = head->next;

                // insert new node at the head of the list
                head->next->prev = node;
                head->next = node;

                this->indices[key] = node;
            } else {
                LRUNode *curr = this->indices[key];
                curr->value = value;

                // move the most recently accessed node to the head of the list
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr->prev = head;
                curr->next = head->next;

                head->next->prev = curr;
                head->next = curr;
            }

            if (this->indices.size() > this->capacity) {
                // evict the tail of the list
                LRUNode *evict = this->tail->prev;
                int evict_key = evict->key;

                this->tail->prev = evict->prev;
                evict->prev->next = this->tail;
                evict->next = nullptr;
                evict->prev = nullptr;
                delete evict;

                this->indices.erase(evict_key);
            }
        }

    private:
        int capacity;
        LRUNode *head;
        LRUNode *tail;
        std::unordered_map<int, LRUNode *> indices;
    };
}  // namespace Leet::Medium
