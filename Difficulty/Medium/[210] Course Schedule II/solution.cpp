/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degrees(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        vector<int> coursesOrder;
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            degrees[pre[0]] += 1;
        }
        while (coursesOrder.size() < numCourses) {
            int i = 0;
            for (; i < degrees.size(); i++) {
                if (degrees[i] == 0) {
                    coursesOrder.push_back(i);
                    degrees[i] = -1;
                    break;
                }
            }
            if (i == degrees.size() && coursesOrder.size() < numCourses)
                return vector<int>();
            for (auto& val : graph[i]) {
                degrees[val] -= 1;
            }
        }
        return coursesOrder;
    }
};
// @lc code=end

