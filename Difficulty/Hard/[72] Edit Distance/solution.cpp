/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//方法不太好，建议去看https://leetcode.com/problems/edit-distance/discuss/25846/C%2B%2B-O(n)-space-DP
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        vector<vector<int>> dp(word2.size(), vector<int>(word1.size(), 0));
        bool equal_flag = false;
        for(int i = 0, j = 0; j < word1.size(); ++j){
            if(word2[i] == word1[j] && !equal_flag){
                equal_flag = true;
                dp[i][j] = j > 0 ? dp[i][j-1] : 0; 
            }else
                dp[i][j] = j > 0 ? dp[i][j-1] + 1 : 1;
        }

        equal_flag = false;
        for (int i = 0, j = 0; i < word2.size(); ++i){
            if(word1[j] == word2[i] && !equal_flag){
                equal_flag = true;
                dp[i][j] = i > 0 ? dp[i - 1][j] : 0; 
            }else
                dp[i][j] = i > 0 ? dp[i - 1][j] + 1 : 1;
        }

        for(int i = 1; i < word2.size(); ++i){
            for(int j = 1; j < word1.size(); ++j){
                if (word2[i] == word1[j]){
                        dp[i][j] = dp[i-1][j-1];
                }
                else
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
            }
        }
        return dp[word2.size() - 1][word1.size() - 1];
    }
};