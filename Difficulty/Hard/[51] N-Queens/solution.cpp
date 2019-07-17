/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n < 1) return res;
        vector<string> puz(n, string(n, '.'));
        vector<vector<int>> positions;
        nQueens(res, puz, 0, n, positions);
        return res;
    }

    void nQueens(vector<vector<string>>& res, vector<string>& puz, int row, int n, vector<vector<int>>& positions){
        if (cur[n-1] != string(n, '.')){
            res.push_back(puz);
            return;
        }
        for (int col = 0; col < n; col++){
            int posId = 0;
            for (auto& pos : positions){
                if (abs(pos[0] - row) == abs(pos[1] - col) || pos[1] == col)
                    break;
                posId++;
            }
            if (posId == positions.size()){
                positions.push_back({row, col});
                puz[row][col] = 'Q';
                nQueens(res, puz, row+1, n, positions);
                puz[row][col] = '.';
                positions.pop_back();
            }
        }    
    }
};