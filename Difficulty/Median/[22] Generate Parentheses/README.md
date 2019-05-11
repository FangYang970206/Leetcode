# 描述 
给定n对括号，编写一个函数来生成格式良好的括号的所有组合。

# 例子

```bash
For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

# 方法
方法1：暴力搜索，搜索所有的解，不满足条件的解不放入res中（只要遇到右括号的个数大于座左括号的个数）

方法2：回溯法，判断条件是右括号的个数大于左括号的个数，使用DFS进行搜索（solution1）。不需要判断条件的是solution2，该解决方案中控制好了右括号的个数不会大于左括号的个数。

方法3：动态规划，参考https://leetcode.com/problems/generate-parentheses/discuss/10369/Clean-Python-DP-Solution