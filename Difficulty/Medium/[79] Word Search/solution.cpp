/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
private:
    bool dfs(vector<vector<char>>& board, int row, int col, const string &word, int start, int M, int N, int sLen)
    {
        char curC;
        bool res = false;
        if( (curC = board[row][col]) != word[start]) return false;
        if(start==sLen-1) return true;
        board[row][col] = '*';
        if(row>0) res = dfs(board, row-1, col, word, start+1, M, N, sLen);
        if(!res && row < M-1) res = dfs(board, row+1, col, word, start+1, M, N, sLen);
        if(!res && col > 0)   res = dfs(board, row, col-1, word, start+1, M, N, sLen);
        if(!res && col < N-1) res = dfs(board,  row, col+1, word, start+1, M, N, sLen);
        board[row][col] = curC;
        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int M, N, sLen = word.size();
        if( (M=board.size()) && (N=board[0].size()) && sLen)
        {
            for(int i=0; i<M; ++i)
                for(int j=0; j<N; ++j)
                    if(dfs(board, i, j, word, 0, M, N, sLen)) return true;
        }
        return false;
    }
};

// 考虑不周的方案，有bug
// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         if (board.empty() || word.empty()) return false;
//         if (board[0].empty()) return false;
//         int height = board.size(), width = board[0].size(), flag = false;
//         vector<pair<int, int>> positions;
//         for (int i = 0; i < height; i++) {
//             for (int j = 0; j < width; j++) {
//                 if (board[i][j] == word[0]){
//                     positions.push_back(pair<int, int>{i, j});
//                     flag = exist_helper(board, word, i, j, 1, flag, positions);
//                     if(flag) return flag;
//                     positions.pop_back();
//                 } 
//             }
//         }
//         return false;
//     }

//     bool exist_helper(vector<vector<char>>& board, const string& word, int i, int j, int num, int& flag, vector<pair<int, int>>& positions) {
//         if(num == word.size())
//             return true;
//         if(i + 1 < board.size()){
//             if (find(positions.begin(), positions.end(), pair<int, int>(i+1, j)) != positions.end()){
//                 if(board[i + 1][j] == word[num]){
//                     positions.push_back(pair<int, int>(i+1, j));
//                     flag = exist_helper(board, word, i+1, j, num+1, flag, positions);
//                     if(flag) return flag;
//                     positions.pop_back();
//                 }
//             }
//         }
//         if (j + 1 < board[0].size()){
//             if (find(positions.begin(), positions.end(), pair<int, int>(i, j+1)) != positions.end()){
//                 if(board[i][j+1] == word[num]){
//                     positions.push_back(pair<int, int>(i, j+1));
//                     flag = exist_helper(board, word, i, j+1, num+1, flag, positions);
//                     if(flag) return flag;
//                     positions.pop_back();
//                 }
//             }
//         }
//         if (j - 1 > 0){
//             if (find(positions.begin(), positions.end(), pair<int, int>(i, j-1)) != positions.end()){
//                 if(board[i][j-1] == word[num]){
//                     positions.push_back(pair<int, int>(i, j-1));
//                     flag = exist_helper(board, word, i, j-1, num+1, flag, positions);
//                     if(flag) return flag;
//                     positions.pop_back();
//                 }
//             }
//         }
//         if (i - 1 > 0){
//             if (find(positions.begin(), positions.end(), pair<int, int>(i-1, j)) != positions.end()){
//                 if(board[i - 1][j] == word[num]) {
//                     positions.push_back(pair<int, int>(i-1, j));
//                     flag = exist_helper(board, word, i-1, j, num+1, flag, positions);
//                     if(flag) return flag;
//                     positions.pop_back();
//                 }   
//             }
//         }
//         return false;
//     } 
// };

