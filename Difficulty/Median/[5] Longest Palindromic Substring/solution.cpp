class Best_Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        string t = "$#";
        for (int i = 0; i < s.size(); ++i){
            t += s[i];
            t += '#';
        }
        vector<int> p(t.size(), 0);
        int mx = 0, id = 0, resLen = 0, resCenter = 0;
        for (int i = 1; i < t.size(); ++i){
            p[i] = mx > i ? min( p[2 * id - i], mx - i ) : 1;
            while (t[ i + p[i] ] == t[ i - p[i] ]) ++p[i];
            if (mx < i + p[i]){
                mx = i + p[i];
                id = i;
            }
            if (resLen < p[i]){
                resLen = p[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - resLen) / 2, resLen - 1);
    }
    
};




// time limit error, don't use it, see readme.
// time limit error, don't use it, see readme.
// time limit error, don't use it, see readme.
class Solution2 {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        string res;
        for (int i = s.size(); i > 0; --i){
            for (int j = 0; j < s.size() - 1; ++j){
                if (isPalindrome(s.substr(j, i - j))){
                    if ((s.substr(j, i - j)).size() > res.size())
                        res = s.substr(j, i - j);
                }
                if ( res.size() > i)
                    return res;
            }
        }
        return res;
    }
    bool isPalindrome(string s){
        int i = 0;
        int j = s.size() - 1;
        while( i <= j ){
            if ( s[i] != s[j] )
                return 0;
            i++;
            j--;
        }
        return 1;
    }
};