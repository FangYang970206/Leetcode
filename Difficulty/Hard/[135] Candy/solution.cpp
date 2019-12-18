/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0, size = ratings.size();
        vector<int> left2right(size, 1);
        vector<int> right2left(size, 1);
        for (int i = 1; i < size; i++){
            if (ratings[i] > ratings[i-1])
                left2right[i] = left2right[i - 1] + 1;
        }
        for (int j = size - 2; j >= 0; j--) {
            if (ratings[j] > ratings[j + 1])
                right2left[j] = right2left[j+1] + 1;
        }
        for (int i = 0; i < size; i++)
            sum += max(left2right[i], right2left[i]);
        return sum;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> candies(size, 1);
        for (int i = 1; i < size; i++){
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i - 1] + 1;
        }
        int sum = candies[size - 1];
        for (int j = size - 2; j >= 0; j--) {
            if (ratings[j] > ratings[j + 1])
                candies[j] = max(candies[j], candies[j+1] + 1);
            sum += candies[j];
        }
        return sum;
    }
};
// @lc code=end

