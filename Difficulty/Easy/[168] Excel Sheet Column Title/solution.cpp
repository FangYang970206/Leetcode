/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        for (int r = n; n || n / 26; n /= 26) {
            r = n % 26;
            if (r == 0) {
                res += 'Z';
                n -= 26;
            }
            else{
                res += 'A' + (r - 1);
                n -= r;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

