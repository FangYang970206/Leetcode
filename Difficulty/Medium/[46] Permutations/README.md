# 问题描述

给定一个没有重复数字的序列，返回其所有可能的全排列。

# 例子

```bash
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

# 方法

采用回溯, 一图胜千言。这里小心一点，在python实现中，不能直接append nums, 这是浅拷贝，当nums变化时，res也会跟着变化，为此，需要加上[:]。

![NewPermutation](assets/NewPermutation.gif)

图片来自于[https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/](https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/)