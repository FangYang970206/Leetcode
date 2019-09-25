/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */
class Solution {
public:
    int numTrees(int n) {
        if (n <= 0) return 0;
        long h_n = 1;
        for (int i = 1; i <= n; ++i)
            h_n = (4 * i - 2) * h_n / (i + 1);
        return h_n;
    }
};

