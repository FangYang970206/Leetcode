# 问题描述

编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例: 

```bash
输入: 19
输出: true
解释: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

# 方法

这题要么遇到1无限循环，要么遇到其他无限循环，那我们只要找到这个循环就知道是否是快乐数字了。

通过快慢指针，在循环中，他们迟早会碰到，当碰上为1时，为快乐数字。