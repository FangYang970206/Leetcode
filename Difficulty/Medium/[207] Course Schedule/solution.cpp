/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegrees(numCourses, 0);
        for (auto& v : prerequisites) {
            graph[v[1]].push_back(v[0]);
            indegrees[v[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front(); q.pop(); numCourses--;
            for (auto i : graph[curr]) {
                indegrees[i]--;
                if (indegrees[i] == 0)
                    q.push(i);
            }
        }
        return numCourses == 0;
    }
};
// @lc code=end

