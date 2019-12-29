class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right, res = 0, len(nums) - 1, 2**31 - 1
        while left < right:
            if nums[left] < nums[right]:
                return min([res, nums[left], nums[0]])
            elif nums[left] == nums[right]:
                left += 1
                right -= 1
            else:
                mid = (left + right) // 2
                if nums[mid] < nums[left]:
                    right = mid
                else:
                    left = mid + 1
        return min([res, nums[left], nums[0]])