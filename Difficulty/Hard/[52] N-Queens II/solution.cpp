class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<vector<int>> positions;
        nQueens(res, 0, n, n, positions);
        return res;
    }

    void nQueens(int& res, int row, int n, int end, vector<vector<int>>& positions){
        if (end == 0){
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
                nQueens(res, row+1, n, end - 1, positions);
                positions.pop_back();
            }
        }    
    }
};