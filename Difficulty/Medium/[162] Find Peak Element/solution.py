class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1: return 0
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            left_value = nums[mid - 1] if (mid - 1) >= 0 else -2**31
            right_value = nums[mid + 1] if (mid + 1) < len(nums) else 2**31 - 1
            if nums[mid] > left_value and nums[mid] > right_value:
                return mid
            if nums[mid] > left_value:
                left = mid + 1
            else:
                right = mid - 1
        if nums[0] > nums[1]:
            return 0
        if nums[len(nums) - 1] > nums[len(nums) - 2]:
            return len(nums) - 1
        return (left + right) // 2