class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        if(strs.size() == 1)
            return strs[0];
        int vec_len = strs.size();
        int str_min_len = strs[0].size();
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].size() < str_min_len)
                str_min_len = strs[i].size();
        }
        for(int i = 0; i < str_min_len; i++){
            for(int j = 0; j < vec_len - 1; j++){
                if(strs[j][i] == strs[j+1][i]){
                    if(j == vec_len - 2 && i + 1 == str_min_len)
                        return strs[j].substr(0, i+1);
                }
                else{
                    if(strs[j].substr(0, i).empty())
                        return "";
                    else
                        return strs[j].substr(0, i);
                }
            }
        }
        return "";
    }
};