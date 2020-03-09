# 问题描述

统计所有小于非负整数 n 的质数的数量。

示例:

```bash
输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
```

# 方法

这题很有趣，虽然标记为简单，但要想实现高性能的方法并不容易。推荐看[高赞解答](https://leetcode-cn.com/problems/count-primes/solution/ru-he-gao-xiao-pan-ding-shai-xuan-su-shu-by-labula/)，一步步很清晰。

我们会发现没有判断质数的函数，因为不需要，当遍历到某个数时，如果check为真，那它就是质数，因为前面的倍数都没有它，非质数会在它自身根号数前有倍数。