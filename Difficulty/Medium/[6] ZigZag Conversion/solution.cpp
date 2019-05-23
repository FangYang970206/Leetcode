class Solution {
public:
    string convert(string s, int numRows) {
        if ( numRows == 1)
            return s;
        vector<string> vs(numRows);
        int law_len = 2 * numRows - 2;
        int temp = 0;
        for (int i = 0; i < s.size(); ++i){
            temp = i % law_len;
            if (temp > numRows - 1)
                temp = (numRows - 1) - (temp - (numRows - 1));
            vs[temp] += s[i];
        }
        string res;
        for (int j = 0; j < vs.size(); ++j)
            res += vs[j];
        return res;
    }
};