# 问题描述
给定一个输入字符串和一个模式，实现正则表达式匹配并支持'.'和'*'.
'.'匹配任何单个字符。'*'匹配前一个元素的零个或多个.
匹配应该覆盖整个输入字符串(而不是部分)。
# 例子
```bash
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
```
# 方法
[动态规划的方法](https://blog.csdn.net/wangyaninglm/article/details/55827721)
- This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are: 
a. P[i][j] = P[i - 1][j - 1], if p[j - 1] != ‘*’ && (s[i - 1] == p[j - 1] || p[j - 1] == ‘.’); 
b. P[i][j] = P[i][j - 2], if p[j - 1] == ‘*’ and the pattern repeats for 0 times;
c. P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == ‘.’), if p[j - 1] == ‘*’ and the pattern repeats for at least 1 times. 
Putting these together, we will have the following code.

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size(); 
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        return dp[m][n];
    }
};
```
