#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        res = []
        for i, s in enumerate(digits):
            temp = []
            s = int(s)
            n = 3 + (abs(s - 8) == 1)
            b = 97 + (s - 2) * 3 + (s > 7)
            if i == 0:
                res = [chr(b + i) for i in range(n)]
            else:
                for r in res:
                    for i in range(n):
                        temp.append(r + chr(b + i))
                res = temp
        return res
