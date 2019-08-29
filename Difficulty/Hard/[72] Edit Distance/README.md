# 问题描述

给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

1.插入一个字符
2.删除一个字符
3.替换一个字符

# 例子

```bash
输入:
输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
```

```bash
输入:
输入: word1 = "intention", word2 = "execution"
输出: 5
解释: 
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
```

# 方法

这题的解法是动态规划，推荐去看https://leetcode.com/problems/edit-distance/discuss/25846/C%2B%2B-O(n)-space-DP，解释得很清楚。

附上他的占用内存小且速度快的方法
```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size(), pre;
        vector<int> cur(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            cur[j] = j;
        }
        for (int i = 1; i <= m; i++) {
            pre = cur[0];
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                int temp = cur[j];
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = pre;
                } else {
                    cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
                }
                pre = temp;
            }
        }
        return cur[n];
    }
};
```