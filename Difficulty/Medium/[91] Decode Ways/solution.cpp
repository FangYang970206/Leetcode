/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return s[0] != '0';
        vector<int> dp(s.size(), 0);
        if (s[0] == '0') return 0;
        if (s[0] - '2' > 0 && s[1] == '0') return 0;
        dp[0] = 1;
        if (s[0] == '1' && s[1] != '0')
            dp[1] = 2;
        else if (s[0] == '2' && s[1] - '0' > 0 && s[1] - '0' <= 6)
            dp[1] = 2;
        else
            dp[1] = 1;
        for (int i = 2; i < s.size(); i++) {
            if (s[i - 1] - '0' > 0 && s[i - 1] - '0' <= 2) {
                if (s[i - 1] == '1' && s[i] != '0') {
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else if (s[i - 1] == '2' && s[i] != '0' && s[i] - '0' <= 6) {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }else if (s[i] == '0')
                    dp[i] = dp[i - 2];
                else
                    dp[i] = dp[i - 1];
            }else if (s[i] != '0')
                dp[i] = dp[i - 1];
            else
                return 0;
        }
        return dp[s.size() - 1];
    }
};

