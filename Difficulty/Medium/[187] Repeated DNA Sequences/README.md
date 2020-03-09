# 问题描述

所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来查找 DNA 分子中所有出现超过一次的 10 个字母长的序列（子串）。

示例：

```bash
输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC", "CCCCCAAAAA"]
```

# 方法

这题挺有意思的，我的解法是常规思路，利用哈希表计数。

有趣的是这题可以用位操作，更加高效，每次移动一位，更改的只是最前面的一个字符去掉，新添加一个字符在最后面，可以将字符串量化成数字，前面的字符去掉量化成左移，后面的字符添加量化成右移取与，具体可以参考[链接](https://leetcode-cn.com/problems/repeated-dna-sequences/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-4-7/)