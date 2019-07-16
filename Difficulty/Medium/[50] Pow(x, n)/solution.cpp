class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long AbsN = n < 0 ? -static_cast<long>(n) : static_cast<long>(n);
        cout << AbsN << endl;
        while (AbsN > 0){
            if (AbsN & 1) res *= x;
            AbsN >>= 1;
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};