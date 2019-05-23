class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addParenthsis(res, "", n, 0);
        return res;
    }
    
    void addParenthsis(vector<string>& vec, string str, int leftParNum, int rightParNum){
        if (leftParNum == 0 && rightParNum == 0){
            vec.push_back(str);
            return;
        }
        if (leftParNum > 0) {addParenthsis(vec, str+'(', leftParNum - 1, rightParNum + 1);}
        if (rightParNum > 0) {addParenthsis(vec, str+')', leftParNum, rightParNum - 1);}
    }
};