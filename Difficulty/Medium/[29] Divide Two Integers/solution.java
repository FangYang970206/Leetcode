//这题采用移位进行逼近，来自https://leetcode-cn.com/problems/divide-two-integers/comments/46284
class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        boolean negative = (dividend > 0) ^ (divisor > 0);
        long t = Math.abs((long)dividend);
        long d = Math.abs((long)divisor);
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            if ((t >> i) >= d) {
                res += (1 << i);
                t -= d << i;
            }
        }
        return negative ? -res : res;
    }
}