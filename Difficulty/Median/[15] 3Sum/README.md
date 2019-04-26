# 描述 
给定一个有n个整数的数组，在数组中是否有a、b、c元素使得a+b+c = 0?找出数组中所有唯一的三胞胎，它们的和为零。

注意：解决方案集不能包含重复的三元组。

# 例子

```bash
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

# 方法
我的方法首先对nums进行排序，然后构建nums字典，key为num, value为key出现的次数，然后求得nums中负数的个数，外层循环迭代为负数，不是负数时显然相加不会等于0. 然后固定负数为target，求取用-target减去内层迭代的数（从外层的索引开始迭代）, 求得find_value，根据字典来进行查找，还有一些判断条件。最后结果824ms, 内存17.4Mb.

# 更好的方法
采用双指针的做法，也是固定负的，跳过一样的数，然而搜索不一样，双指针分别从两边开始搜索，总和大于0，则应该右边指针减1，小于0则左边指针加1，直到遇到相等的，append到列表中，然后跳过重复的数。(576ms, 14.9Mb)
```python
# 来自https://leetcode.com/problems/3sum/discuss/232712/Best-Python-Solution-(Explained)
class Solution(object):
	def threeSum(self, nums):
		res = []
		nums.sort()
		length = len(nums)
		for i in xrange(length-2): #[8]
			if nums[i]>0: break #[7]
			if i>0 and nums[i]==nums[i-1]: continue #[1]

			l, r = i+1, length-1 #[2]
			while l<r:
				total = nums[i]+nums[l]+nums[r]

				if total<0: #[3]
					l+=1
				elif total>0: #[4]
					r-=1
				else: #[5]
					res.append([nums[i], nums[l], nums[r]])
					while l<r and nums[l]==nums[l+1]: #[6]
						l+=1
					while l<r and nums[r]==nums[r-1]: #[6]
						r-=1
					l+=1
					r-=1
		return res
```
