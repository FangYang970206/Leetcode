class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return 0;
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ')+1);
        if (s[0] == '-' || s[0] == '+')
            s.erase(0, 1);
        if (s.size() == 1) return s[0] >= '0' && s[0] <= '9';
        size_t e_pos = s.find_first_of('e');
        if (e_pos != string::npos && e_pos != s.size() - 1 && e_pos != 0){
            int n = s[e_pos + 1] == '-' || s[e_pos + 1] == '+';
            if (e_pos + 1 == s.size() - 1 && n == 1) return false;
            else return checkNumber(s.substr(0, e_pos), false) & checkNumber(s.substr(e_pos+1+n), true);
        }
        else if (e_pos == s.size() - 1 || e_pos == 0) 
            return false;
        else
            return checkNumber(move(s), false);
    }

    bool checkNumber(string&& s, bool dot_exist){
        if (s.size() == 1 && s[0] == '.') return false;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] >= '0' && s[i] <= '9')
                continue;
            else if (s[i] == '.' && !dot_exist)
                dot_exist = true;
            else 
                return false;
        }
        return true;
    }
};