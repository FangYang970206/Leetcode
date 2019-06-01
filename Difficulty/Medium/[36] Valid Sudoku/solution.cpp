class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, int> _map;
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                if (board[i][j] != '.'){
                    string b = '.' + to_string(board[i][j]) + '.';
                    if (_map.find(to_string(i) + b) != _map.end() || 
                        _map.find(b + to_string(j)) != _map.end() || 
                        _map.find(to_string(i / 3) + b + to_string(j / 3)) != _map.end())
                        return false;
                    else{
                        _map.insert({to_string(i) + b, 1});
                        _map.insert({b + to_string(j), 1});
                        _map.insert({to_string(i / 3) + b + to_string(j / 3), 1});
                    }
                }
            }
        }
        return true;
    }
};