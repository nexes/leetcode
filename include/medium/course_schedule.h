#pragma once

#include <queue>
#include <vector>

using std::queue;
using std::vector;

namespace Leet::Medium {
    // There are a total of numCourses courses you have to take, labeled from 0 to
    // numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai,
    // bi] indicates that you must take course bi first if you want to take course ai.

    // For example, the pair [0, 1], indicates that to take course 0 you have to first
    // take course 1. Return true if you can finish all courses. Otherwise, return false.

    // Example 1:
    // Input: numCourses = 2, prerequisites = [[1,0]]
    // Output: true
    // Explanation: There are a total of 2 courses to take.
    // To take course 1 you should have finished course 0. So it is possible.

    // Example 2:
    // Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    // Output: false
    // Explanation: There are a total of 2 courses to take.
    // To take course 1 you should have finished course 0, and to take course 0 you should
    // also have finished course 1. So it is impossible.

    // Constraints:
    // 1 <= numCourses <= 2000
    // 0 <= prerequisites.length <= 5000
    // prerequisites[i].length == 2
    // 0 <= ai, bi < numCourses
    // All the pairs prerequisites[i] are unique.
    struct CourseSchedule
    {
        // We use a DAG and perform Topological Sort
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
        {
            vector<vector<int>> dag(numCourses);
            vector<int> indegree(numCourses, 0);
            queue<int> q;

            for (vector<int> pre : prerequisites) {
                indegree[pre[0]]++;
                dag[pre[1]].push_back(pre[0]);
            }

            for (int i = 0; i < numCourses; i++) {
                if (indegree[i] == 0)
                    q.push(i);
            }

            int visited = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();

                visited++;
                for (int v : dag[u]) {
                    indegree[v]--;
                    if (indegree[v] == 0) {
                        q.push(v);
                    }
                }
            }

            return visited == numCourses;
        }

        // if we want to return the order (there can be multiple orders) we can add the
        // node in the while loop
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
        {
            vector<vector<int>> dag(numCourses);
            vector<int> indegree(numCourses, 0);
            vector<int> sorted;
            queue<int> q;

            for (vector<int> pre : prerequisites) {
                indegree[pre[0]]++;
                dag[pre[1]].push_back(pre[0]);
            }

            for (int i = 0; i < numCourses; i++) {
                if (indegree[i] == 0)
                    q.push(i);
            }

            int visited = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();

                sorted.push_back(u);

                visited++;
                for (int v : dag[u]) {
                    indegree[v]--;
                    if (indegree[v] == 0) {
                        q.push(v);
                    }
                }
            }

            return visited == numCourses ? sorted : vector<int>();
        }
    };
}  // namespace Leet::Medium