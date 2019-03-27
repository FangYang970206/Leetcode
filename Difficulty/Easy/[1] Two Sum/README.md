# 我的方法
使用双重循环，第一重从左往右固定索引，计算需要查找的结果，第二层循环从固定索引出发依次向右查找第一层计算的结果。时间复杂度$O(n^2)$, 空间复杂度$O(1)$.

# 更多的方法
1. 双行程哈希表
首先，构建map<num, index>的哈希表，存入对应的值和索引，遍历map, 计算target-num, 利用哈希表常熟时间的寻址，只要当前索引不与前面的num索引冲突，即找到结果。时间复杂度$O(n)$, 空间复杂度$O(n)$.
```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_dict = {value: index for index, value in enumerate(nums)}
        for i, num in enumerate(nums):
            find_value = target - num
            if find_value in nums_dict and nums_dict[find_value] != i:
                return [i, nums_dict[find_value]]
```
2. 单行程哈希表(最优)
与上面一种的区别在于不先将所有的值和索引都放入map中，在遍历中放入，因为可能在前几个数字中就找到了满足的结果，这种方法在复杂度上与上一种一样，但实际要优于上一种方法。
```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_dict = {}
        for i, num in enumerate(nums):
            find_value = target - num
            if find_value in nums_dict:
                return [i, nums_dict[find_value]]
            nums_dict[num] = i
```