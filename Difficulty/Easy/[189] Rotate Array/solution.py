class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n < 2: return
        k = k % n
        tmp = [0] * k
        for i in range(k):
            tmp[i] = nums[n - k + i]
        for i in range(n - k - 1, -1, -1):
            nums[i + k] = nums[i]
        for i in range(k):
            nums[i] = tmp[i]

        