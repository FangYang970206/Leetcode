# 问题描述

给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。

示例 1:

```bash
输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
```

示例 2:

```bash
输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。
```

说明:

- 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
- 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。

# 方法

这题考察的是桶排序，题目要求空间和时间都在O(n)，所以排序不是基于比较，基于非比较的，对于给的nums，先求出nums的最小值min和最大值max，那么min_gap就是(max - min) / (nums.size() - 1), 也就是均等gap，根据这一特点，我们可以建桶，数量是nums.size() - 1，第i桶所统计的范围是(min + (i - 1) * min_gap, l + i * min_gap), 可以看到范围的下限和上限分别是min和max，在每个桶中，我们只需要统计最小值和最大值，其他值不用管，这是因为桶中最大的gap就是min_gap, 所以不用管，遍历一遍nums，更新每个桶的最小值和最大值，然后遍历一遍桶，然后后一个桶的最小值减去前一个桶的最大值即为桶之间的gap，以此来更新maxGap，需要注意的是，有的桶为没有数，最小值和最大值为默认，需要continue掉。