/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int num = 1 << n;
        vector<int> res(num, 0);
        for (int i = 1; i < num; ++i) {
            if (i & 1)
                res[i] = res[i - 1] & 1 ? res[i - 1] ^ 1 : res[i - 1] | 1;
            else
            {
                int j = getPosition(i);
                res[i] = res[i - 1] & (1 << (j - 1)) ? res[i - 1] ^ (1 << (j - 1)) : res[i - 1] | (1 << (j - 1));
            }
        }
        return res;
    }
    int getPosition(int n){
        int i = 2;
        while (! ((n = n >> 1) & 1)) i++;
        return i;
    }
};

