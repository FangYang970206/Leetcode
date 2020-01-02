/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-';
        int64_t n = abs(int64_t(numerator));
        int64_t d = abs(int64_t(denominator));
        res += to_string(n / d);
        if (n % d == 0) return res;
        res += '.';
        unordered_map<int, int> map;
        for (int64_t r = n % d; r; r %= d) {
            if (map.count(r) > 0) {
                res.insert(map[r], 1, '(');
                res += ')';
                break;
            }
            map[r] = res.size();
            r *= 10;
            res += to_string(r / d);
        }
        return res;
    }
};
// @lc code=end

