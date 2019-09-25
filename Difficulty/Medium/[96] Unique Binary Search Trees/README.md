# 问题描述

给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

# 例子

```bash
输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

# 方法

这道题有两种解法，一种是动态规划，推荐去看https://leetcode-cn.com/problems/unique-binary-search-trees/solution/hua-jie-suan-fa-96-bu-tong-de-er-cha-sou-suo-shu-b/

还有一种是数学归纳法，更加简单，不过不易想到Catalan数，查看https://blog.csdn.net/jtlyuan/article/details/7440591
