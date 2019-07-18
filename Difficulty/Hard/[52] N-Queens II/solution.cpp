class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        if (n < 1) return res;
        vector<string> puz(n, string(n, '.'));
        vector<vector<int>> positions;
        nQueens(res, puz, 0, n, positions);
        return res;
    }

    void nQueens(int& res, vector<string>& puz, int row, int n, vector<vector<int>>& positions){
        if (puz[n-1] != string(n, '.')){
            res++;
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