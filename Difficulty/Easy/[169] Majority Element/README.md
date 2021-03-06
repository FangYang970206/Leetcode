# 问题描述

给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:

```bash
输入: [3,2,3]
输出: 3
```

示例 2:

```bash
输入: [2,2,1,1,1,2,2]
输出: 2
```

# 方法

这一题常规思路是用哈希表记录数字出现的次数，时间复杂度是O(n), 空间复杂度是O(n), 不过这次还有更好的方法Boyer-Moore投票算法，来自[官方题解](https://leetcode-cn.com/problems/majority-element/solution/qiu-zhong-shu-by-leetcode-2/)，由于nums中的众数比长度的一半还多，所以进行计数抵消，最后剩下的一定是最大众数。
