/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int a_size = a.size(), b_size = b.size(), sum = 0;
        int loop_i = min(a_size, b_size);
        bool carry = false;
        string res;
        for (int i = 1; i <= loop_i; ++i){
            sum = (a[a_size - i] - '0') + (b[b_size - i] - '0') + carry;
            if (sum < 2){
                carry = false;
                res = char('0' + sum) + res;
            }
            else{
                carry = true;
                res = char('0' + (sum - 2)) + res;
            }
        } 
        int other = abs(a_size - b_size);
        if (carry){
            if (a_size > b_size){
                for(int j = 1; j <= other; j++){
                    int sum_temp = (a[other - j] - '0') + carry;
                    if (sum_temp < 2){
                        res = char(sum_temp + '0') + res;
                        carry = 0;
                    }else{
                        res = '0' + res;
                        carry = 1;
                    }
                }
            }else{
                for(int j = 1; j <= other; j++){
                    int sum_temp = (b[other - j] - '0') + carry;
                    if (sum_temp < 2){
                        res = char(sum_temp + '0') + res;
                        carry = 0;
                    }else{
                        res = '0' + res;
                        carry = 1;
                    }
                }
            }
        }else{
            if (a_size > b_size)
                res = a.substr(0, other) + res;
            else
                res = b.substr(0, other) + res;
        }
        if (carry)
            res = '1' + res;
        return res;
    }
};

