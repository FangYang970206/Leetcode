class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if len(nums) < 2: return 0
        l, u = 2 ** 31 - 1, -2 ** 31
        for num in nums:
            l = min(l, num)
            u = max(u, num)
        gap = math.ceil((u - l) / (len(nums) - 1))
        bucketsMIN, bucketsMAX = [2 ** 31 - 1] * (len(nums) - 1), [-2 ** 31] * (len(nums) - 1)
        for num in nums:
            if num == l or num == u:
                continue
            idx = int((num - l) / gap)
            bucketsMIN[idx] = min(num, bucketsMIN[idx])
            bucketsMAX[idx] = max(num, bucketsMAX[idx])
        maxGap, pre = -2 ** 31, l
        for i in range(len(nums) - 1):
            if bucketsMIN[i] == 2 ** 31 - 1 and bucketsMAX[i] == -2 ** 31:
                continue
            maxGap = max(maxGap, bucketsMIN[i] - pre)
            pre = bucketsMAX[i]
        return max(maxGap, u - pre)