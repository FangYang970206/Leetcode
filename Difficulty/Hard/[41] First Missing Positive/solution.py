class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        s = set()
        for num in nums:
            if num > 0 and num < len(nums):
                s.add(num)
        min_v, max_v = len(nums), 0
        for e in s:
            if e > max_v:
                max_v = e
            if e < min_v:
                min_v = e
        if min_v != 1:
            return 1
        if max_v - min_v == len(s) - 1:
            return max_v + 1
        for i in range(2, max_v):
            if i not in s:
                return i
        
                
        