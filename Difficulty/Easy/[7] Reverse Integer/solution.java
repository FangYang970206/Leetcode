class Solution {
    public int reverse(int x) {
        if (x == Integer.MIN_VALUE) return 0;
        boolean minus = x < 0;
        x = x < 0 ? -x : x;
        long res = 0;
        while (x != 0) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        res = minus ? -res : res;
        if (res > Integer.MAX_VALUE || res < Integer.MIN_VALUE) return 0;
        return (int)res;
    }
}