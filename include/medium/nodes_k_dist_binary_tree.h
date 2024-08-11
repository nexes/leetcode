#pragma once

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../treenode.h"

using std::unordered_map;
using std::unordered_set;
using std::vector;

namespace Leet::Medium {
    // Given the root of a binary tree, the value of a target node target, and an integer
    // k, return an array of the values of all nodes that have a distance k from the
    // target node. You can return the answer in any order.

    // Example 1:
    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
    // Output: [7,4,1]
    // Explanation: The nodes that are a distance 2 from the target node (with value 5)
    // have values 7, 4, and 1.

    // Example 2:
    // Input: root = [1], target = 1, k = 3
    // Output: []

    // Constraints:
    // The number of nodes in the tree is in the range [1, 500].
    // 0 <= Node.val <= 500
    // All the values Node.val are unique.
    // target is the value of one of the nodes in the tree.
    // 0 <= k <= 1000
    struct KDistanceBinaryTree
    {
        using TreeGraph = unordered_map<Leet::TreeNode *, vector<Leet::TreeNode *>>;
        using seenList = unordered_set<Leet::TreeNode *>;

        vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
        {
            std::queue<TreeNode *> q;
            vector<int> found;
            TreeGraph graph;
            seenList seen;

            q.push(root);

            // tree to bidirectional-graph
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();

                if (node->left != nullptr) {
                    graph[node].push_back(node->left);
                    graph[node->left].push_back(node);
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    graph[node].push_back(node->right);
                    graph[node->right].push_back(node);
                    q.push(node->right);
                }
            }

            // searching the graph is easier than the tree
            dfs(graph, seen, target, found, k);
            return found;
        }

        void dfs(TreeGraph &graph, seenList &seen, TreeNode *target, vector<int> &found,
                 int k)
        {
            if (k == 0) {
                found.push_back(target->val);
                return;
            }

            seen.insert(target);

            for (int i = 0; i < graph[target].size(); i++) {
                if (seen.count(graph[target][i]) == 0)
                    dfs(graph, seen, graph[target][i], found, k - 1);
            }
        }
    };
}  // namespace Leet::Medium