class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
        if (divisor == -1 && dividend != INT_MIN) return -dividend;
        int res = 0;
        bool sign =  dividend > 0 ^ divisor > 0 ? false : true;
        long m = 1, temp = 1;
        long dvd = labs(dividend), dvs = labs(divisor);
        while (dvd >= dvs){
            temp = dvs, m = 1;
            while(temp << 1 <= dvd){
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            res += m;
        }
        return sign ? res : -res;
    }
};