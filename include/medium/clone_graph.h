#pragma once

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;

// Definition of a Node by Leetcode
class Node
{
public:
    int val;
    std::vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = std::vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node *>();
    }
    Node(int _val, std::vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

namespace Leet::Medium {
    // Given a reference of a node in a connected undirected graph.
    // Return a deep copy (clone) of the graph.
    // Each node in the graph contains a value (int) and a list (List[Node]) of its
    // neighbors.

    // class Node {
    //     public int val;
    //     public List<Node> neighbors;
    // }

    // Test case format:
    // For simplicity, each node's value is the same as the node's index (1-indexed). For
    // example, the first node with val == 1, the second node with val == 2, and so on.
    // The graph is represented in the test case using an adjacency list. An adjacency
    // list is a collection of unordered lists used to represent a finite graph. Each list
    // describes the set of neighbors of a node in the graph. The given node will always
    // be the first node with val = 1. You must return the copy of the given node as a
    // reference to the cloned graph.

    // Example 1:
    // Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
    // Output: [[2,4],[1,3],[2,4],[1,3]]
    // Explanation: There are 4 nodes in the graph.
    // 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
    // 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
    // 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
    // 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

    // Example 2:
    // Input: adjList = [[]]
    // Output: [[]]
    // Explanation: Note that the input contains one empty list. The graph consists of
    // only one node with val = 1 and it does not have any neighbors.

    // Example 3:
    // Input: adjList = []
    // Output: []
    // Explanation: This an empty graph, it does not have any nodes.

    // Constraints:
    // The number of nodes in the graph is in the range [0, 100].
    // 1 <= Node.val <= 100
    // Node.val is unique for each node.
    // There are no repeated edges and no self-loops in the graph.
    // The Graph is connected and all nodes can be visited starting from the given node.
    struct CloneGraph
    {
        Node *cloneGraph(Node *node)
        {
            if (node == nullptr)
                return node;

            std::queue<Node *> nodequeue;
            unordered_set<int> seen;
            unordered_map<int, Node *> nodemap;

            nodequeue.push(node);
            seen.insert(node->val);

            while (!nodequeue.empty()) {
                Node *n = nodequeue.front();
                nodequeue.pop();

                if (nodemap.count(n->val) == 0)
                    nodemap[n->val] = new Node(n->val);

                for (int i = 0; i < n->neighbors.size(); i++) {
                    int neighbor_val = n->neighbors[i]->val;

                    if (nodemap.count(neighbor_val) == 0)
                        nodemap[neighbor_val] = new Node(neighbor_val);

                    nodemap[n->val]->neighbors.push_back(nodemap[neighbor_val]);

                    if (seen.count(neighbor_val) == 0) {
                        seen.insert(neighbor_val);
                        nodequeue.push(n->neighbors[i]);
                    }
                }
            }

            return nodemap[node->val];
        }
    };
}  // namespace Leet::Medium