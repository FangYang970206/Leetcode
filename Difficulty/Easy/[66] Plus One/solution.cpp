/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return vector<int>(1,1);
        int carry = 0;
        digits[digits.size() - 1] += 1;
        for (auto it = digits.rbegin(); it != digits.rend(); it++){
            *it += carry;
            if (*it != 10){
                carry = 0;
                break;
            }
            else{
                carry = 1;
                *it = 0;
            }
        }
        if (carry == 1){
            digits.push_back(1);
            swap(digits[0], digits[digits.size() - 1]);
            return digits;
        }
        else
            return digits;
    }
};

