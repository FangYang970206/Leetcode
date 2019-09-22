/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int min_len;
        if (s.size() >= 11)
            min_len = 2;
        else
            min_len = 1;
        vector<string> res;
        restoreIpAddressesHelper(res, s, string(), 0, 0, min_len);
        return res;
    }

    void restoreIpAddressesHelper(vector<string>& res, const string& s, string tmp, int count, int begin, int min_len) {
        if (count == 4) {
            if (tmp.size() == s.size() + 3)
                res.push_back(tmp);
            return;
        }

        for (int i = min_len; i <= 3; ++i) {
            if (s[begin] == '0' && i > 1) return;
            if (begin + i > s.size()) return;
            if (stoi(s.substr(begin, i)) <= 255){
                if (tmp.empty())
                    restoreIpAddressesHelper(res, s, tmp + s.substr(begin, i), count+1, begin + i, min_len);
                else
                    restoreIpAddressesHelper(res, s, tmp + '.' + s.substr(begin, i), count+1, begin + i, min_len);    
            }
        }
    }
};

