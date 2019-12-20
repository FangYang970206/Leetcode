# 问题描述

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

- 拆分时可以重复使用字典中的单词。
- 你可以假设字典中没有重复的单词。

示例 1：

```bash
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
```

示例 2：

```bash
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
```

示例 3：

```bash
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
```

# 方法

这一题使用动态规划来做，首先将wordDict转成unordered_set, 便于快速查找，构造动态dp的vector以及记录dp为1为positions的vector，然后遍历字符串，对于索引j，先判断s[0:j)是否在wordDict中，在则令dp[j]为1， positions记录此时的j，否则遍历positions，判断s[p:j)是否在wordDict中，是则令dp[j]为1，positions记录此时的j。遍历一遍后，最后输出dp[size].