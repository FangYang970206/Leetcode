# 描述 
给定一个包含n个整数的数组和一个整数目标，在数字中找到三个整数，使它们的和最接近目标。返回三个整数的和。您可以假设每个输入都只有一个解。

# 例子

```bash
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

# 方法
还是使用双指针，与problem15的解法一样，不同的是在求和时判断求和与target的距离，距离变小则替换结果。