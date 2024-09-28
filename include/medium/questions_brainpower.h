#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi,
    // brainpoweri].

    // The array describes the questions of an exam, where you have to process the
    // questions in order (i.e., starting from question 0) and make a decision whether to
    // solve or skip each question. Solving question i will earn you pointsi points but
    // you will be unable to solve each of the next brainpoweri questions. If you skip
    // question i, you get to make the decision on the next question.

    // For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
    // If question 0 is solved, you will earn 3 points but you will be unable to solve
    // questions 1 and 2. If instead, question 0 is skipped and question 1 is solved, you
    // will earn 4 points but you will be unable to solve questions 2 and 3. Return the
    // maximum points you can earn for the exam.

    // Example 1:
    // Input: questions = [[3,2],[4,3],[4,4],[2,5]]
    // Output: 5
    // Explanation: The maximum points can be earned by solving questions 0 and 3.
    // - Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
    // - Unable to solve questions 1 and 2
    // - Solve question 3: Earn 2 points
    // Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.

    // Example 2:
    // Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
    // Output: 7
    // Explanation: The maximum points can be earned by solving questions 1 and 4.
    // - Skip question 0
    // - Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
    // - Unable to solve questions 2 and 3
    // - Solve question 4: Earn 5 points
    // Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.

    // Constraints:
    // 1 <= questions.length <= 105
    // questions[i].length == 2
    // 1 <= pointsi, brainpoweri <= 105
    struct QuestionsBrainpower
    {
        // ------------------ RECUSION : TLE ------------------
        long long addPoints_recursion(vector<vector<int>>& questions, int idx)
        {
            if (idx >= questions.size())
                return 0;

            return std::max(addPoints_recursion(questions, idx + questions[idx][1] + 1) +
                                questions[idx][0],
                            addPoints_recursion(questions, idx + 1));
        }

        long long mostPoints_recursion(vector<vector<int>>& questions)
        {
            vector<long long> points(questions.size(), -1);
            return addPoints_recursion(questions, 0);
        }

        // ------------------ TOP DOWN : DP O(n^2) ------------------
        long long addPoints_topdown(vector<vector<int>>& questions,
                                    vector<long long>& points, int idx)
        {
            if (idx >= questions.size())
                return 0;

            if (points[idx] != -1)
                return points[idx];

            points[idx] = std::max(
                addPoints_topdown(questions, points, idx + questions[idx][1] + 1) +
                    questions[idx][0],
                addPoints_topdown(questions, points, idx + 1));

            return points[idx];
        }

        long long mostPoints_topdown(vector<vector<int>>& questions)
        {
            vector<long long> points(questions.size(), -1);
            return addPoints_topdown(questions, points, 0);
        }

        // ------------------ BOTTOM UP : DP O(n^2) ------------------
        long long mostPoints(vector<vector<int>>& questions)
        {
            int len = questions.size();

            vector<long long> points(len, -1);
            points[len - 1] = questions[len - 1][0];

            for (int i = len - 2; i >= 0; i--) {
                int nextIdx = i + questions[i][1] + 1;
                points[i] = questions[i][0];

                if (nextIdx < len)
                    points[i] += points[nextIdx];

                points[i] = std::max(points[i], points[i + 1]);
            }

            return points[0];
        }
    };
}  // namespace Leet::Medium