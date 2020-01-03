# 问题描述

给定一个整数 n，返回 n! 结果尾数中零的数量。

示例 1:

```bash
输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。
```

示例 2:

```bash
输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.
```

说明: 你算法的时间复杂度应为 O(log n) 。

# 方法

这题O(n)的方法很简单，计算有多少个5就可以了，但不经优化会超时。自己根据答案知道了规律，写出来但不够清晰，还是没有看清本质。[windliang](https://leetcode-cn.com/problems/factorial-trailing-zeroes/solution/xiang-xi-tong-su-de-si-lu-fen-xi-by-windliang-3/)的解答很清晰，值得一看，每隔一个5，就会多一个0，每隔一个25，出现5x5，会多两个0，每隔一个125，出现5x5x5，多三个0。于是代码如下：

```java
public int trailingZeroes(int n) {
    int count = 0;
    while (n > 0) {
        count += n / 5;
        n = n / 5;
    }
    return count;
}
```