class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res, temp;
        if (digits.size() == 0)
            return res;
        int s = 0, n = 0, b = 0;
        string ts;
        for (int i = 0; i < digits.size(); ++i){
            s = int(digits[i]) - 48;
            n = 3 + (abs(s - 8) == 1);
            b = 97 + 3 * (s - 2) + (s > 7);
            if (i == 0)
                for (int j = 0; j < n; ++j){
                    ts = char(b + j);
                    res.push_back(ts);
                }
            else{
                for (int j = 0; j < res.size(); ++j){
                    for (int k = 0; k < n; ++k)
                        temp.push_back(res[j] + char(b + k));
                }
                res = temp;
            }
            temp.clear();
        }
        return res;
    }
};