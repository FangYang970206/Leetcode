class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        string longest_sub_str = "";
        int same_char_index = 0;
        for(int i = 0; i < s.size(); ++i){
            longest_sub_str += s[i];
            if (longest_sub_str.size() > 1){
                same_char_index = longest_sub_str.substr(0, longest_sub_str.size()-1).find(s[i]);
                if(same_char_index != string::npos){
                    if(max_length < longest_sub_str.size() - 1)
                        max_length = longest_sub_str.size() - 1;
                    longest_sub_str = longest_sub_str.substr(same_char_index+1);
                }
            }
        }
    if (longest_sub_str.size() > max_length)
        return longest_sub_str.size();
    else
        return max_length;
    }
};