/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] < '0' || (s[left] > '9' && s[left] < 'A') || (s[left] > 'Z' && s[left] < 'a') || s[left] > 'z') {
                left++;
                continue;                
            }
            if (s[right] < '0' || (s[right] > '9' && s[right] < 'A') || (s[right] > 'Z' && s[right] < 'a') || s[right] > 'z') {
                right--;
                continue;                
            }
            if (tolower(s[left]) == tolower(s[right])) {
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true; 
    }
};
// @lc code=end

