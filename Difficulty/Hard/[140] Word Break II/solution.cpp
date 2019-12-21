/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

// TIME LIMIT ERROR
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        vector<vector<string>> vvs;
        vector<string> vs;
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        wordBreakHelper(s, uset, vs, vvs, 0);
        for (auto& vs_tmp: vvs) {
            string tmp;
            for (int i = 0; i < vs_tmp.size(); i++) {
                tmp += vs_tmp[i];
                if (i != vs_tmp.size() - 1)
                    tmp += " ";
            }
            res.push_back(tmp);
        }
        return res;
    }

    void wordBreakHelper(const string& s, const unordered_set<string>& wordDict, vector<string>& vs, vector<vector<string>>& vvs, int cur_id) {
        if (cur_id == s.size()) {
            vvs.push_back(vs);
            return;
        }
        for (int i = cur_id; i <= s.size(); i++) {
            if (wordDict.find(s.substr(cur_id, i - cur_id)) != wordDict.end()) {
                vs.push_back(s.substr(cur_id, i - cur_id));
                wordBreakHelper(s, wordDict, vs, vvs, i);
                vs.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> mp;
        return dfs(s, words, mp);
    }
private:
    vector<string> dfs(string s, unordered_set<string>& wordDict, unordered_map<string, vector<string>>& mp) {
        if (mp.find(s) != mp.end()) {
            return mp[s];
        }
        vector<string> sentences;
        if (s.empty()) {
            return {""};
        }
        for (string word : wordDict) {
            if (s.size() >= word.size() && s.substr(0, word.size()) == word) {
                vector<string> subs = dfs(s.substr(word.size()), wordDict, mp);
                for (string sub : subs) {
                    sentences.push_back(word + (sub.size() ? " " + sub : ""));
                }
            }
        }
        mp[s] = sentences;
        return sentences;
    }
};
// @lc code=end

