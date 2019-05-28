# 问题描述

给定一个按升序排序的整数数组，找出给定目标值的起始和结束位置。

算法的运行时复杂度必须是O(log n)。

如果数组中没有找到目标，返回[- 1,1]。

# 例子

```bash
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

# 方法

首先使用二分法查找target, 然后根据寻找到的target的索引向两边进行扩散, 直到两个的数不等于target停止，得到最后的范围。

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums or target < nums[0] or target > nums[-1]:
            return [-1, -1]
        li, hi = 0, len(nums) - 1
        # 二分法查找
        while li < hi:
            mid = (li + hi) // 2
            if nums[mid] == target:
                break
            elif nums[mid] > target:
                hi = mid - 1
            else:
                li = mid + 1
        # 相等时代表要不只有一个target，要么没有target
        if li == hi:
            return [-1, -1] if nums[li] != target else [li, li]
        else:
            #两边扩散
            li, hi = mid, mid
            while True:
                if li == 0:
                    break
                if nums[li - 1] == nums[mid]:
                    li -= 1
                else:
                    break
            while True:
                if hi == len(nums) - 1:
                    break
                if nums[hi + 1] == nums[mid]:
                    hi += 1
                else:
                    break
            return [li, hi]
```