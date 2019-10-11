# 问题描述

给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

# 例子

```bash
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false
```

# 方法

这题使用动态规划进行求解，s1和s2的元素索引分别用i和j表示，动态规划要解决的是已知s1[0: i)和s2[0: j)与s3[0: i + j)匹配，s1[i]或者s2[j]是否与s3[i + j]匹配。这题可以不需要二维数组dp，一维足够了。