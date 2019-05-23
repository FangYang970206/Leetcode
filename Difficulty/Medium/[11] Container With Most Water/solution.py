class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxArea = 0
        i, j = 0, len(height) - 1
        while(i < j):
            h = min(height[i], height[j])
            sub = j - i
            maxArea = max(maxArea, h*sub)
            if h == height[i]:
                while(i < j and h >= height[i+1]):
                    i += 1
                if sub == j - i:
                    i += 1
            else:
                while(i < j and h >= height[j-1]):
                    j -= 1
                if sub == j - i:
                    j -= 1
        return maxArea