/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = squareSum(slow);
            fast = squareSum(fast);
            fast = squareSum(fast);
        }while(slow != fast);

        return slow == 1;
    }

    int squareSum(int n) { 
        int res = 0;
        for(; n; n /= 10) {
            int num = n % 10;
            res += num * num;
        }
        return res;
    }
};
// @lc code=end

