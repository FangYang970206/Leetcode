class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        if len(nums) == 3:
            return nums[0] + nums[1] + nums[2]
        nums = sorted(nums)
        res = nums[0] + nums[1] + nums[2]
        
        for i in range(len(nums) - 2):
            l, r = i + 1, len(nums) - 1
            while l < r:
                sum = nums[i] + nums[l] + nums[r]
                if sum == target:
                    return sum
                
                if abs(res - target) >= abs(sum - target):
                    res = sum
                
                if sum > target:
                    r -= 1
                elif sum < target:
                    l += 1
        
        return res