/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty()) return res;
        vector<string> path;
        partitionHelper(0, s, path, res);
        return res;
    }

    void partitionHelper(int index, const string& s, vector<string>& path, vector<vector<string>>& res){
        if (index == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                partitionHelper(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int begin, int end){
        while (begin <= end){
            if (s[begin++] != s[end--])
                return false;
        }
        return true;
    }
};
// @lc code=end

