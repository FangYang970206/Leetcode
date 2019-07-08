/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; i--){
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--){
                int mu = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                res[i + j + 1] = mu % 10 + '0';
                carry = mu / 10;
            }
            res[i] += carry;
        }
        size_t startPos = res.find_first_not_of('0');
        if (startPos != string::npos)
            return res.substr(startPos);
        return "0";
    }
};