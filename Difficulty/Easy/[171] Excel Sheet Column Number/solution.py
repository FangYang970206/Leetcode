class Solution:
    def titleToNumber(self, s: str) -> int:
        length, res = len(s) - 1, 0
        for i in range(len(s)):
            res += ((ord(s[i]) - ord('A')) + 1) * math.pow(26, length - i)
        return int(res)