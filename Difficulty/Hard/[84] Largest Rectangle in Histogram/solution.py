class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ret, index = 0, []
        heights.append(0)
        for i in range(0, len(heights)):
            while len(index) > 0 and heights[index[-1]] >= heights[i]:
                h = heights[index[-1]]
                index.pop()
                sidx = index[-1] if len(index) > 0 else -1
                ret = max(ret, h * (i - sidx - 1))
            index.append(i)
        return ret