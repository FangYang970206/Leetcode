/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<string> visited(1, beginWord);
        int level = 1, res = 0, visit_begin = 0;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++){
                string curr = q.front(); q.pop();
                for (int j = visit_begin; j < visited.size(); ++j)
                    wordSet.erase(visited[j]);
                visit_begin = visited.size();
                addNeighboursToQ(curr, wordSet, visited, q, endWord, level, res);
                if (res != 0) return res;
            }
            level++;
        }
        return 0;
    }

    void addNeighboursToQ(string& curr, unordered_set<string>& wordSet, vector<string>& visited, queue<string>& q, const string& endWord, int& level, int& res){
        for (string s: wordSet){
            if (isOneCharDiff(curr, s)){
                q.push(s);
                visited.push_back(s);
                if (s == endWord) {
                    res = level + 1;
                    return;
                }
            }
        }
    }

    bool isOneCharDiff(const string& s1, const string& s2){
        int num = 0;
        for (int i = 0; i < s1.size(); i++){
            if (s1[i] != s2[i]) num++;
            if (num > 1) return false;
        }
        return num == 1;
    }
};
// @lc code=end

