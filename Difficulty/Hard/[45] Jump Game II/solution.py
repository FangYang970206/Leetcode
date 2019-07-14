class Solution:
    def jump(self, nums: List[int]) -> int:
        step, cur_index= 0, 0
        while cur_index != len(nums) - 1:
            if cur_index + nums[cur_index] >= len(nums) - 1:
                return step + 1
            max_shift = 0
            sub_optimal_index = 0
            for i in range(1, nums[cur_index] + 1):
                if i + nums[i+cur_index] > max_shift:
                    max_shift = i + nums[i + cur_index]
                    sub_optimal_index = cur_index + i
            cur_index = sub_optimal_index
            step += 1
        return step    