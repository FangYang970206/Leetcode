class Solution:
    def canJump(self, nums: List[int]) -> bool:
        cur_index= 0
        while cur_index != len(nums) - 1:
            if cur_index + nums[cur_index] >= len(nums) - 1:
                return True
            if nums[cur_index] <= 0:
                return False
            max_shift = 0
            sub_optimal_index = 0
            for i in range(1, nums[cur_index] + 1):
                if i + nums[i+cur_index] > max_shift:
                    max_shift = i + nums[i + cur_index]
                    sub_optimal_index = cur_index + i
            cur_index = sub_optimal_index
        return True