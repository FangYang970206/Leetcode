class Solution {
public:
    int countPrimes(int n) {
        vector<bool> check(n, true);
        for (int i = 2; i * i < n; i++) {
            if (check[i]) {
                for (int j = i * i; j < n; j += i){
                    check[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (check[i])
                count++;
        }
        return count;
    }
};