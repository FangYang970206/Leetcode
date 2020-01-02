/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int vs1_size = version1.size();
        int vs2_size = version2.size();
        string vs1_str, vs2_str;
        int idx1 = 0, idx2 = 0;
        int count1, count2;
        int vs1_num, vs2_num;
        while (idx1 < vs1_size || idx2 < vs2_size) {
            if (idx1 < vs1_size) {
                count1 = version1.find_first_of('.', idx1);
                if (count1 != string::npos)
                    vs1_str = version1.substr(idx1, count1 - idx1);
                else
                    vs1_str = version1.substr(idx1);
                int pos1 = vs1_str.find_first_not_of('0');
                if (pos1 != string::npos)
                    vs1_str = vs1_str.substr(pos1);
                else
                    vs1_str = "";
            }
            if (idx2 < vs2_size) {
                count2 = version2.find_first_of('.', idx2);
                if (count2 != string::npos)
                    vs2_str = version2.substr(idx2, count2 - idx2);
                else
                    vs2_str = version2.substr(idx2);
                int pos2 = vs2_str.find_first_not_of('0');
                if (pos2 != string::npos)
                    vs2_str = vs2_str.substr(pos2);
                else
                    vs2_str = "";
            }
            vs1_num = vs1_str.empty() ? -1 : stoi(vs1_str);
            vs2_num = vs2_str.empty() ? -1 : stoi(vs2_str);
            if (vs1_num > vs2_num)
                return 1;
            else if (vs1_num < vs2_num) {
                return -1;
            }
            else{
                if (idx1 < vs1_size) {
                    if (count1 == string::npos)
                        idx1 = vs1_size;
                    else
                        idx1 = count1 + 1;
                }
                if (idx2 < vs2_size) {
                    if (count2 == string::npos)
                        idx2 = vs2_size;
                    else
                        idx2 = count2 + 1;
                }
                vs1_str = "";
                vs2_str = "";
            }
        }
        return 0;
    }
};
// @lc code=end

