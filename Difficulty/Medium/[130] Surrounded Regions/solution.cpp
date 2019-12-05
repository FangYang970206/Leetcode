/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int h = board.size(), w = board[0].size();
        bool flag = false;
        unordered_set<string> s;
        vector<pair<int, int>> tmp;
        for (int i = 1; i < h - 1; ++i) {
            for (int j = 1; j < w - 1; ++j) {
                if (board[i][j] == 'O'){
                    if (s.find(to_string(i) + to_string(j)) != s.end())
                        continue;
                    if (board[i-1][j] == 'O' || board[i][j-1] == 'O')
                        continue;
                    flag = search_path(board, i, j, i, j, tmp);
                    if(flag){
                        for (auto& elem: tmp){
                            s.insert(to_string(elem.first) + to_string(elem.second));
                            board[elem.first][elem.second] = 'O';
                        }
                    }else{
                        for (auto& elem: tmp){
                            board[elem.first][elem.second] = 'X';
                        }
                    }
                    tmp.clear();
                }
            }
        }
    }

    bool search_path(vector<vector<char>>& board, int i, int j, int cur_i, int cur_j, vector<pair<int, int>>& v){
        bool flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
        v.push_back(pair<int, int>(cur_i, cur_j));
        board[cur_i][cur_j] = 't';
        if (cur_i == 0 || cur_j == 0 || cur_i == board.size() - 1 || cur_j == board[0].size() - 1)
            return true;
        if (board[cur_i+1][cur_j] == 'O')
            flag1 = search_path(board, i, j, cur_i + 1, cur_j, v);
        if (board[cur_i][cur_j+1] == 'O')
            flag2 = search_path(board, i, j, cur_i, cur_j + 1, v);
        if (cur_i > i || cur_j > j){
            if (board[cur_i-1][cur_j] == 'O')
                flag3 = search_path(board, i, j, cur_i - 1, cur_j, v);
            if (board[cur_i][cur_j - 1] == 'O')
                flag4 = search_path(board, i, j, cur_i, cur_j - 1, v);
        }
        return flag1 || flag2 || flag3 || flag4;
    }
};
// @lc code=end

