# 描述 
给定一个包含n个整数的数组和一个整数目标，nums中是否有元素a、b、c和d使得a+b+c+d = target?找出数组中所有唯一的四胞胎，给出目标的和。

Note: 解集不能包含重复的四联体。
# 例子

```bash
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
```

# 方法
方法1：对应solution1, 与3sum一样，采用双指针，不同的是,外层多了一个循环.(1142ms)

方法2：对应solution2，与方法一不同的是，在`while l < r`中加入了一个条件判断，利用的是排序数组的特性，如果要找的另外两个数（双指针指向）之和大于当前区域最大数的两倍或者小于当前区域最小数的两倍，则退出当前循环。（200ms）

方法3：来自Accepted Solutions Runtime Distribution，使用了更多的优化，搜寻数字采用字典，搜索时间下降，每一个循环都加上了方法2的条件判断，进行更少的循环，速度更快。（64ms)

其中c++实现对python版本的方法3进行了重写，最后结果Runtime: 12 ms, faster than 99.47% of C++ online submissions for 4Sum.
Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for 4Sum.

方法2参考的solution可以泛化到N-sum，使用递归，值得一看。
```python
def fourSum(self, nums, target):
    def findNsum(l, r, target, N, result, results):
        if r-l+1 < N or N < 2 or target < nums[l]*N or target > nums[r]*N:  # early termination
            return
        if N == 2: # two pointers solve sorted 2-sum problem
            while l < r:
                s = nums[l] + nums[r]
                if s == target:
                    results.append(result + [nums[l], nums[r]])
                    l += 1
                    while l < r and nums[l] == nums[l-1]:
                        l += 1
                elif s < target:
                    l += 1
                else:
                    r -= 1
        else: # recursively reduce N
            for i in range(l, r+1):
                if i == l or (i > l and nums[i-1] != nums[i]):
                    findNsum(i+1, r, target-nums[i], N-1, result+[nums[i]], results)

    nums.sort()
    results = []
    findNsum(0, len(nums)-1, target, 4, [], results)
    return results
```