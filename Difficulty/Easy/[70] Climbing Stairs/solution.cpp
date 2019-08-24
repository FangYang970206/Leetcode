/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> res(n, 0);
        res[0] = 1;
        res[1] = 2;
        for (int i = 2; i < n; ++i)
            res[i] = res[i-1] + res[i-2];
        return res[n - 1];
    }
};

