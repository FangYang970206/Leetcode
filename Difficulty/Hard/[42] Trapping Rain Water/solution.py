class Solution:
    def trap(self, height: List[int]) -> int:
        l, r, lower, level, water = 0, len(height)-1, 0, 0, 0
        while l < r:
            if height[r] > height[l]:
                lower = height[l]
                l += 1
            else:
                lower = height[r]
                r -= 1
            level = max(lower, level)
            water += level - lower
        return water