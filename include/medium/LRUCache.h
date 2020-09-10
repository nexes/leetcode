#pragma once

#include <iostream>
#include <iterator>
#include <unordered_map>
#include <list>

namespace Leet::Medium {
    // Design and implement a data structure for Least Recently Used (LRU) cache.
    // It should support the following operations: get and put.
    //
    // get(key) - Get the value (will always be positive) of the key if the key exists
    // in the cache, otherwise return -1.
    //
    // put(key, value) - Set or insert the value if the key is not already present.
    // When the cache reached its capacity, it should invalidate the least recently
    // used item before inserting a new item. The cache is initialized with a positive capacity.
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
        // we can assument a negative capacity is not given for this problem
        LRUCache(int capacity) : capacity(capacity), lru(), lookup(capacity) {}

        // O(1)
        int get(int key)
        {
            auto pos = lookup.find(key);

            if (pos == lookup.end())
                return -1;

            auto new_pos = lru.insert(lru.begin(), {key, pos->second->second});

            lru.erase(pos->second);
            lookup[key] = new_pos;

            return lru.front().second;
        }

        // O(1)
        void put(int key, int value)
        {
            if (lru.size() >= capacity) {
                auto rem = lru.back();

                lru.pop_back();
                lookup.erase(rem.first);
            }

            auto pos = lru.insert(lru.begin(), {key, value});
            lookup[key] = pos;
        }

    private:
        int capacity;
        std::list<std::pair<int, int>> lru;
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator> lookup;
    };
}  // namespace Leet::Medium
