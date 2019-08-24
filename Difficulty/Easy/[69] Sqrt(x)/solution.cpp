/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

//二分法
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int mid = x >> 1, left = 0, right = x;
        while(left < right){
            if (mid > x / mid)
                right = mid;
            else if (mid < x / mid)
                left = mid;
            else
                return mid;
            mid = (left + right) >> 1;
            if (mid == left) return mid;
        }
    }
};

// 牛顿法
class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }
};