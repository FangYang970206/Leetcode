/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> nums;
        nums.reserve(n);
        string res;
        vector<int> Cumulate;
        Cumulate.reserve(n);
        for (int i = 1; i <= n; i++)
            nums.push_back(to_string(i));
        int CumulateTemp = 1;
        for (int i = 1; i < n; i++){
            CumulateTemp *= i;
            Cumulate.push_back(CumulateTemp);
        }
        int j = 2;
        k --;
        while(res.size() != n - 1){
            int q = k / Cumulate[n - j];
            res += nums[q];
            nums.erase(nums.begin() + q);
            k = k %  Cumulate[n - j++];
        }
        return res + nums[0];
    }
};

