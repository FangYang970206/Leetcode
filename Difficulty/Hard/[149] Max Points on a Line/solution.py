class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n, ans = len(points), 0
        for i in range(n):
            counter = dict()
            dup = 1
            for j in range(i + 1, n):
                if points[j][0] == points[i][0] and points[j][1] == points[i][1]:
                    dup += 1
                else:
                    dx = points[j][0] - points[i][0]
                    dy = points[j][1] - points[i][1]
                    g = self.gcd(dx, dy)
                    counter[str(dx // g) + '_' + str(dy // g)] = counter.get(str(dx // g) + '_' + str(dy // g), 0) + 1
            ans = max(ans, dup)
            for v in counter.values():
                ans = max(ans, v + dup)
        return ans

    def gcd(self, a, b):
        while b:
            a = a % b
            a, b = b, a
        return a               
