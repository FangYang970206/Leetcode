/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
private:
    unordered_set<string> wordList;
    vector<vector<string>> ans;
    unordered_set<string> visited;
            
    int level = 1;
    int minLevel = INT_MAX;
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,vector<string> &words ) {

        //Putting all words in a set
        for(auto word: words)
            wordList.insert(word);
        //wordList.insert(endWord); Cant insert endWord now
            
        //Queue of Paths
        queue<vector<string>> q;
        q.push({beginWord});
        

        while (!q.empty()) 
        {
            vector<string> path = q.front(); q.pop();
            
            if (path.size() > level)
            {
                for (string w : visited) 
                    wordList.erase(w);
                
                if (path.size() > minLevel)
                    break;
                else
                    level = path.size();
            }
            
            
            string lastWord = path.back();
            
            addNeighboursToQ(lastWord,path,q,endWord);
        }
        
        return ans;
    }
    
    void addNeighboursToQ(string curr,vector<string> path,queue<vector<string>> &q,const string &endWord)
    {
            for(int i=0;i<curr.size();i++) 
            {
                char originalChar = curr[i];

                for(int j=0;j<26;j++)
                {
                    curr[i] = j + 'a';
                    
                    if(wordList.find(curr)!=wordList.end())
                    {
                        vector<string> newpath = path;
                        newpath.push_back(curr);
                        
                        visited.insert(curr);
                        
                        if (curr == endWord) {
                            minLevel = level;
                            ans.push_back(newpath);
                        }
                        else
                            q.push(newpath);
                        
                    }
                }
                
                curr[i] = originalChar;
            }
    }
};


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return vector<vector<string>>();
        vector<string> newWordList;
        for(auto& s : wordList){
            if (stringDiff(s, beginWord) != beginWord.size() || 
                stringDiff(s, endWord) != endWord.size())
                newWordList.push_back(s);
        }
        vector<vector<string>> res;
        unordered_map<string, int> dict;
        for (auto& s : newWordList){
            if (s == endWord) dict[s] = 1;
            else dict[s] = 0;
        }
        vector<string> ladder(1, beginWord);
        int min_height = INT_MAX;
        findLadder(res, beginWord, endWord, newWordList, ladder, 0, min_height, dict);
        return res;
    }

    void findLadder(vector<vector<string>>& res, string beginWord, string endWord, vector<string>& wordList, vector<string>& ladder, int height, int& min_height, unordered_map<string, int>& dict) {
        if (height > min_height) return;
        if (stringDiff(beginWord, endWord) == 1)
        {
            ladder.push_back(endWord);
            if (height < min_height){
                res.clear();
                min_height = height;
            }
            res.push_back(ladder);
            ladder.pop_back();
            return;
        }
        for (auto & s : wordList) {
            if (stringDiff(beginWord, s) == 1 && dict[s] == 0) {
                ladder.push_back(s);
                dict[s] = 1;
                findLadder(res, s, endWord, wordList, ladder, height + 1, min_height, dict);
                dict[s] = 0;
                ladder.pop_back();
            }
        }
    }

    int stringDiff(string word1, string word2) {
        int count = 0;
        for (int i = 0; i < word1.size(); ++i) {
            if (word1[i] != word2[i]) count++;
        }
        return count;
    }
};
// @lc code=end

