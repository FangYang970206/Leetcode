class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int tmp = 0;
        while (tmp < x) {
            tmp = tmp * 10 + x % 10;
            x /= 10;
        }
        return tmp == x || (tmp / 10) == x;
    }
}