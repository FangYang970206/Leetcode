/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
// 0ms
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        long num = 5;
        unordered_map<int,int> m{{num,1}};
        while (num <= n) {
            num *= 5;
            m[num] = m[num / 5] * 5 + 1;
        }
        while (n >= 5) {
            num /= 5;
            int q = n / num;
            if (q != 0) {
                n -= num * q;
                count += m[num] * q;
            }
        }
        return count;
    }
};

// 1772ms
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0, num = n / 5;
        for (int i = 1; i <= num; i++) {
            int tmp = i;
            while (tmp % 5 == 0) {
                count += 1;
                tmp /= 5;
            }
            count += 1;
        }
        return count;
    }
};
// @lc code=end

