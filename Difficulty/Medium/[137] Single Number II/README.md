# 问题描述

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

```bash
输入: [2,2,3,2]
输出: 3
```

示例 1:

```bash
输入: [0,1,0,1,0,1,99]
输出: 99
```

# 方法

单个数字这种题型考的是位运算，输入数组每个元素都出现了k次，只有一个只出现了p次，求那个单独的只出现p次的数。做法是利用m个数（2^m > k)构造出k进制，出现k次的元素全部变为0，剩余的元素即为所求元素，求解模板如下：

```bash
for (int i : nums) {
    xm ^= (xm-1 & ... & x1 & i);
    xm-1 ^= (xm-2 & ... & x1 & i);
    .....
    x1 ^= i;
    
    mask = ~(y1 & y2 & ... & ym) where yj = xj if kj = 1, and yj = ~xj if kj = 0 (j = 1 to m).

    xm &= mask;
    ......
    x1 &= mask;
}
```

原始的英文solution观看困难，推荐看[链接1](http://liadbiz.github.io/leetcode-single-number-problems-summary/)和[链接2](https://blog.csdn.net/wlwh90/article/details/89712795)的解读版.
