class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;
        int index = 0;
        for (int i = s.size() - 1; i >=0; --i){
            if (s[i] != ' '){
                index = i;
                break;
            }                                                                                          
        }
        int num = 0;
        for (int i = index; i >= 0; --i){
            if (s[i] == ' ')
                return num;
            else
                num += 1;
        }
        return num;
    }
};