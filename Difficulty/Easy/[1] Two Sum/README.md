# 我的方法
使用双重循环，第一重从左往右固定索引，计算需要查找的结果，第二层循环从固定索引出发依次向右查找第一层计算的结果。时间复杂度$O(n^2)$, 空间复杂度$O(1)$.

# 更多的方法
1. 双行程哈希表
行程哈希表(第一次行程遍历nums生成字典，第二次遍历nums找结果）: 首先，构建dict<num, index>的字典（哈希表），存入对应的值和索引，遍历map, 计算target-num, 利用哈希表常数时间的寻址，只要在字典中找到的索引不与当前索引一样，即找到结果。时间复杂度$O(n)$, 空间复杂度$O(n)$.
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
单行程哈希表（遍历一次nums）：与上面一种的区别在于不先将所有的值和索引都放入map中，在遍历中依次放入，少了一次遍历的时间，速度更快占用内存更小。时间复杂度$O(n)​$, 空间复杂度$O(n)。
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
运行时间与内存占用比较：
|方法 | 时间 | 内存|
|----- | ---- | ---- |
|常规   | 3244ms| 13.9Mb|
|双行程 | 56ms| 15Mb  |
|单行程 | 40ms| 14.1Mb|