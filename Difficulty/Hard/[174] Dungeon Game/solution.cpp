/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n=dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,INT_MAX));
        dp[m-1][n] = 1;
        for(int i = m-1; i>=0; i--)
        {
            for(int j =n-1; j>=0; j--)
            {
                int val = min(dp[i+1][j], dp[i][j+1])-dungeon[i][j];
                dp[i][j] = max(val, 1);
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n=dungeon[0].size();
        vector<int> dp(n+1, INT_MAX);
        dp[n-1] = 1;
        for(int i = m-1; i>=0; i--)
            for(int j =n-1; j>=0; j--)
                dp[j] = max(min(dp[j], dp[j+1])-dungeon[i][j], 1);
        return dp[0];
    }
};


//糟糕的做法，没有AC
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> h(n, 0);
        vector<int> g(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    if (dungeon[i][j] > 0) {
                        h[j] = 0;
                        g[j] = dungeon[i][j];
                    } else {
                        h[j] = dungeon[i][j];
                        g[j] = 0;
                    }
                }
                else if (j == 0 || i == 0) {
                    if (dungeon[i][j] > 0) {
                        if (i == 0) {
                            g[j] = g[j-1] + dungeon[i][j];
                            h[j] = h[j-1];
                        }else{
                            g[j] = g[j] + dungeon[i][j];
                        }
                    } else {
                        if (i == 0) {
                            if (g[j-1] > 0) {
                                if (g[j-1] + dungeon[i][j] > 0) {
                                    g[j] = g[j-1] + dungeon[i][j];
                                    h[j] = h[j - 1];
                                } else {
                                    g[j] = 0;
                                    h[j] = h[j-1] + g[j-1] + dungeon[i][j];
                                }
                            } else {
                                g[j] = 0;
                                h[j] = h[j-1] + dungeon[i][j];
                            }
                        } else{
                            if (g[j] > 0) {
                                if (g[j] + dungeon[i][j] > 0) {
                                    g[j] += dungeon[i][j];
                                }else{
                                    h[j] += g[j] + dungeon[i][j];
                                    g[j] = 0;
                                }
                            }else
                                h[j] += dungeon[i][j];
                        }
                    }
                } else{
                    if (dungeon[i][j] > 0) {
                        if (h[j] > h[j-1]) {
                            g[j] += dungeon[i][j];
                        } else if(h[j] == h[j-1]){
                            g[j] = max(g[j], g[j-1]) + dungeon[i][j];
                        }else{
                            h[j] = h[j-1];
                            g[j] = dungeon[i][j] + g[j-1];
                        }
                    } else {
                        int upper = g[j] + dungeon[i][j];
                        int left = g[j-1] + dungeon[i][j];
                        if (upper < 0)
                            upper += h[j];
                        else
                            upper = h[j];
                        if (left < 0)
                            left += h[j-1];
                        else
                            left = h[j - 1];
                        if (upper > left) {
                            if (g[j] + dungeon[i][j] > 0) {
                                g[j] = g[j] + dungeon[i][j];
                            }else{
                                h[j] += g[j] + dungeon[i][j];
                                g[j] = 0;
                            }
                        }else{
                            if (g[j-1] + dungeon[i][j] > 0) {
                                g[j] = g[j-1] + dungeon[i][j];
                                h[j] = h[j-1];
                            }else{
                                g[j] = 0;
                                h[j] = g[j-1] + dungeon[i][j] + h[j-1];
                            }
                        }
                    }
                }
            }
        }
        return abs(h[n-1]) + 1;
    }
};
// @lc code=end

