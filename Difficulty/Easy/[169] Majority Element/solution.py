class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        half_len, m = len(nums) // 2, dict()
        for num in nums:
            if m.get(num, 0):
                m[num] += 1
            else:
                m[num] = 1
            if m[num] > half_len:
                return num