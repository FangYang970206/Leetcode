# 问题描述

给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

```bash
输入:
11110
11010
11000
00000

输出: 1
```

示例 2:

```bash
输入:
11000
11000
00100
00011

输出: 3
```

# 方法

这题我采用的dfs，用unordered-set记录看过了岛屿（C++版本），不过，需要这题更好的是直接在grid修改1为0，处理更简单（参考解答实现的python版本）

另外，这题还可以使用并查集这种数据结构，要快一些。