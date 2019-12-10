# 问题描述

给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。

示例:

```bash
输入: "aab"
输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
```

# 方法

以下解法说明来自于[heiyanbin](https://leetcode.com/problems/palindrome-partitioning-ii/discuss/42199/My-DP-Solution-(-explanation-and-code))这个问题虽然是上一个问题的延申，但解法确完全不同，字符串最优化问题一般采取的是动态规划算法，而遍历求集合问题一般使用dfs回溯。这题首先使用一个二维数组pal，pal[i][j]为真表示s[i..j]是回文，还有一个d[n]数组记录最小cut数，d[i]表示s[i..n-1]的最小cut数，通过两个循环i，j逆序判断回文来更新d[n]，最终d[0]即为最优解。