#pragma once

#include <vector>
#include <../treenode.h>

namespace Leet::Medium
{
    // Implement an iterator over a binary search tree (BST). Your iterator
    // will be initialized with the root node of a BST. Calling next() will
    // return the next smallest number in the BST.

    // Example:
    //   7
    //  / \
    // 3   15
    //    /  \
    //   9    20

    // BSTIterator iterator = new BSTIterator(root);
    // iterator.next();    // return 3
    // iterator.next();    // return 7
    // iterator.hasNext(); // return true
    // iterator.next();    // return 9
    // iterator.hasNext(); // return true
    // iterator.next();    // return 15
    // iterator.hasNext(); // return true
    // iterator.next();    // return 20
    // iterator.hasNext(); // return false

    // Note 1:
    // next() and hasNext() should run in average O(1) time and uses O(h) memory,
    // where h is the height of the tree.

    // Note 2:
    // You may assume that next() call will always be valid, that is, there will
    // be at least a next smallest number in the BST when next() is called.
    struct BSTIterator
    {

    public:
        BSTIterator(Leet::TreeNode *root) : index(0),
                                            flat_tree()
        {
            flatten(root);
        }

        int next()
        {
            // this problem guarantees next() will be valid, so we wont check
            return flat_tree.at(index++);
        }

        bool hasNext()
        {
            return index < flat_tree.size();
        }

    private:
        void flatten(Leet::TreeNode *root)
        {
            if (!root)
                return;

            flatten(root->left);
            flat_tree.push_back(root->val);
            flatten(root->right);
        }

    private:
        int index;
        std::vector<int> flat_tree;
    };
} // namespace Leet::Medium
