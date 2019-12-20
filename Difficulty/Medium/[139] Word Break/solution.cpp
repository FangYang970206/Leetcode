/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <unordered_set>
#include <vector>

using namespace std;

// 12ms
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        size_t size = s.size();
        vector<int> dp(size + 1, false);
        vector<int> positions;
        for (int i = 0; i <= size; ++i) {
            if (uset.find(s.substr(0, i)) != uset.end()) {
                    positions.push_back(i);
                    dp[i] = true;
            }else{
                for (auto p : positions) {
                    if (uset.find(s.substr(p, i - p)) != uset.end()) {
                        positions.push_back(i);
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[size];
    }
};

// 20ms
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        size_t size = s.size();
        vector<int> dp(size + 1, false);
        for (int i = 0; i <= size; ++i) {
            if (uset.find(s.substr(0, i)) != uset.end()) 
                dp[i] = true;
            else{
                for (int j = 0; j < i; j++) {
                    if (dp[j]){
                        if (uset.find(s.substr(j, i - j)) != uset.end()) {
                            dp[i] = true;
                            break;
                        }
                    } 
                }
            }
        }
        return dp[size];
    }
};
// @lc code=end

