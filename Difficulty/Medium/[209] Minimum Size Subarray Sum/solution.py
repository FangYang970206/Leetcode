class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        if s <= 0 or not nums: return 0
        left, right, sum = 0, 0, 0
        length, minLen = len(nums), 2**31 - 1
        while right < length:
            sum += nums[right]
            right += 1
            while sum >= s:
                minLen = min(minLen, right - left)
                sum -= nums[left]
                left += 1
        return 0 if minLen == 2 ** 31 - 1 else minLen 
