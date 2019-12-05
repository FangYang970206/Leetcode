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

// 并查集方案，来自https://leetcode.com/problems/surrounded-regions/discuss/41617/Solve-it-using-Union-Find
class UF
{
private:
	int* id;     // id[i] = parent of i
	int* rank;  // rank[i] = rank of subtree rooted at i (cannot be more than 31)
	int count;    // number of components
public:
	UF(int N)
	{
		count = N;
		id = new int[N];
		rank = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
			rank[i] = 0;
		}
	}
	~UF()
	{
		delete [] id;
		delete [] rank;
	}
	int find(int p) {
		while (p != id[p]) {
			id[p] = id[id[p]];    // path compression by halving
			p = id[p];
		}
		return p;
	}
	int getCount() {
		return count;
	}
	bool connected(int p, int q) {
		return find(p) == find(q);
	}
	void connect(int p, int q) {
		int i = find(p);
		int j = find(q);
		if (i == j) return;
		if (rank[i] < rank[j]) id[i] = j;
		else if (rank[i] > rank[j]) id[j] = i;
		else {
			id[j] = i;
			rank[i]++;
		}
		count--;
	}
};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int n = board.size();
        if(n==0)    return;
        int m = board[0].size();
        UF uf = UF(n*m+1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||i==n-1||j==0||j==m-1)&&board[i][j]=='O') // if a 'O' node is on the boundry, connect it to the dummy node
                    uf.connect(i*m+j,n*m);
                else if(board[i][j]=='O') // connect a 'O' node to its neighbour 'O' nodes
                {
                    if(board[i-1][j]=='O')
                        uf.connect(i*m+j,(i-1)*m+j);
                    if(board[i+1][j]=='O')
                        uf.connect(i*m+j,(i+1)*m+j);
                    if(board[i][j-1]=='O')
                        uf.connect(i*m+j,i*m+j-1);
                    if(board[i][j+1]=='O')
                        uf.connect(i*m+j,i*m+j+1);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!uf.connected(i*m+j,n*m)){ // if a 'O' node is not connected to the dummy node, it is captured
                    board[i][j]='X';
                }
            }
        }
    }
};
// @lc code=end

