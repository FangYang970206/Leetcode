class Solution {
public:
    int romanToInt(string s) {
        map<char, int> RtoI = { {'I', 1}, {'V', 5},
                                {'X', 10}, {'L', 50},
                                {'C', 100}, {'D', 500},
                                {'M', 1000}
                              };
        int res = 0;
        int str_len = s.size();
        for(int i = 0; i < str_len; i++){
            if (i == str_len - 1)
                res += RtoI[s[i]];
            else{
                if (RtoI[s[i]] >= RtoI[s[i+1]])
                    res += RtoI[s[i]];
                else
                    res -= RtoI[s[i]];
            }
        }
        return res;
    }
};