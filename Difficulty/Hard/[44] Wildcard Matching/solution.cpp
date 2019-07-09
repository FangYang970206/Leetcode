class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size(), i = 0, j = 0, sTrack = -1, pTrack = -1;
        while (i < sLen){
            if ((s[i] == p[j]) || (p[j] == '?')) {i++; j++; continue;}
            if (p[j] == '*') {sTrack=i; pTrack=j++; continue;}
            if (pTrack >= 0) {j = pTrack+1; i=++sTrack; continue;}
            return false;
        }
        while(p[j] == '*') j++;
        return j==pLen;
    }
};