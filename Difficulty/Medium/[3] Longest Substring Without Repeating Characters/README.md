# 问题描述
给定一个字符串，在不重复字符的情况下找出**最长子字符串**的长度。

# 例子
```bash
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

# 方法
循环遍历字符串的每个字符，对每个字符相加，新加入的字符要查找前面的字符串是否存在新加入的字符，不存在继续下一个字符，存在比较当前最大长度。

# 更好的方法
利用hashmap的方法：
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //建立ascii码的字典，字典的键代表字符，字典的值代表字符所在的索引，初始为0
        int m[256] = {0}, res = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            //if中第一个条件判断当前s[i]是否出现过，第二个条件是当出现重复字符时，更换left的位置为重复的字符的前一个索引
            if (m[s[i]] == 0 || m[s[i]] < left) {
                res = max(res, i - left + 1);
            } else {
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        return res;
    }
};
```
下面这个与上面类似，用到了unordered_map构建字典:
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = 0, i = 0, n = s.size();
        unordered_map<char, int> m;
        for (int i = 0; i < n; ++i) {
            left = max(left, m[s[i]]);
            m[s[i]] = i + 1;
            res = max(res, i - left + 1);
        }
        return res;
    }
};
```