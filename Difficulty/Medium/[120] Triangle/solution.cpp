/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        int min_sum = INT_MAX, height = triangle.size(), path_sum = triangle[0][0];
        minimumTotalHelper(triangle, path_sum, height, min_sum, 1, 0);
        return min_sum;
    }

    void minimumTotalHelper(vector<vector<int>>& triangle, int& path_sum, int height, int& min_sum, int cur_height, int cur_index) {
        if (cur_height == height) {
            if (path_sum < min_sum) min_sum = path_sum;
            return;
        }
        
        path_sum += triangle[cur_height][cur_index];
        minimumTotalHelper(triangle, path_sum, height, min_sum, cur_height+1, cur_index);
        path_sum -= triangle[cur_height][cur_index];
        
        path_sum += triangle[cur_height][cur_index + 1];
        minimumTotalHelper(triangle, path_sum, height, min_sum, cur_height+1, cur_index+1);
        path_sum -= triangle[cur_height][cur_index + 1];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        int height = triangle.size();
        for (int i = 1; i < height; i++){
            for (int j = 0; j < i + 1; j++){
                if (j == 0) triangle[i][j] += triangle[i-1][j];
                else if (j == i) triangle[i][j] += triangle[i-1][j-1];
                else{
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
                }
            }
        }
        return *min_element(triangle[height-1].begin(), triangle[height-1].end());
    }
};
// @lc code=end

