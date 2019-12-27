class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return string();
        string res;
        int i = s.size() - 1, begin = INT_MAX, end = INT_MAX;
        while (i >= 0) {
            if (isspace(s[i])) {
                if (begin != end)
                    begin = i;
            }else{
                if (begin == end)
                    end = i;
            }
            if (end > begin) {
                res += s.substr(begin + 1, end - begin);
                res += {" "};
                end = begin = i;
            }
            i -= 1;
        }
        if (end == begin)
            return res.substr(0, res.size() - 1);
        else
            return res + s.substr(0, end + 1);
    }
};