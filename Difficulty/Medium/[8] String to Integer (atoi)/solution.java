class Solution {
    public int myAtoi(String str) {
        boolean minus = false;
        int i = 0, len = str.length();
        while (i < len && str.charAt(i) == ' ') i++;
        if (i < len) {
            if (str.charAt(i) == '-') {
                minus = true;
                i++;
            } else if (str.charAt(i) == '+') {
                i++;
            }
        }
        if (i == len) return 0;
        long res = myAtoiHelper(str, i, minus);
        return (int)res;
    }

    public long myAtoiHelper(String str, int i, boolean minus) {
        if (str.charAt(i) < '0' || str.charAt(i) > '9') return 0;
        long res = 0;
        int len = str.length();
        while (i < len) {
            char c = str.charAt(i++);
            if (c >= '0' && c <= '9') {
                res = res * 10 + (minus ? ('0' - c) : (c - '0'));
            } else {
                return res;
            }
            if (res > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            if (res < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
        }
        return res;
    }
}