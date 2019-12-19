class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0, mask = 0;
        for (auto num : nums) {
            x2 ^= x1 & num;
            x1 ^= num;
            mask = ~(x1 & x2);
            x2 &= mask;
            x1 &= mask;
        }
        return x1;
    }
};