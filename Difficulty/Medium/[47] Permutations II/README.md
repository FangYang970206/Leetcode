# 问题描述

给定一个可包含重复数字的序列，返回所有不重复的全排列。

# 例子

```bash
输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

# 方法

跟上一题一样，采用回溯, 不过需要小心的是，需要消除冗余，第一种是两个一样的数进行交换（不包含自己和自己），第二种是交换的数前面已经有相同的数进行交换了。这两种情况可以通过下面集合问题来规避。

```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        size = len(nums)
        self.permutation(res, 0, size, nums)
        return res
    
    def permutation(self, res, begin, size, nums):
        if begin == size - 1:
            res.append(nums[:])
            return
        record = set()
        for i in range(begin, size):
            if nums[i] in record:
                continue
            record.add(nums[i])
            nums[begin], nums[i] = nums[i], nums[begin]
            self.permutation(res, begin + 1, size, nums)
            nums[begin], nums[i] = nums[i], nums[begin]
```