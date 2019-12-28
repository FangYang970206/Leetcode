class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) < 3: return min(nums)
        left, right = 0, len(nums) - 1
        if nums[left] < nums[right]:
            return nums[left]
        if nums[right] < nums[right - 1]:
            return nums[right]
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < nums[mid + 1] and nums[mid] < nums[mid - 1]:
                return nums[mid]
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid