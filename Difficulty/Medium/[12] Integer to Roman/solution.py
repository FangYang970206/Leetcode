#
# @lc app=leetcode id=12 lang=python3
#
# [12] Integer to Roman
#
class Solution:
    def intToRoman(self, num: int) -> str:
        res = ''
        res, num = self.func1(res, num, 1000, 'M')
        res, num = self.func1(res, num, 100, 'C')
        res, num = self.func1(res, num, 10, 'X')
        res, num = self.func1(res, num, 1, 'I')
        return res
    def func1(self, res, num, div, c):
        if num >= div:
            if c == 'M':
                res += int(num / div) * c
                num = num % div
            elif c == 'C':
                res, num = self.func2(res, num, div, c, 'D', 'M')
            elif c == 'X':
                res, num = self.func2(res, num, div, c, 'L', 'C')
            elif c == 'I':
                res, num = self.func2(res, num, div, c, 'V', 'X')
        return res, num
    def func2(self, res, num, div, c, top1, top2):
        temp = int(num / div)
        if temp != 4 and temp != 9:
            if temp < 4:
                res += c * temp
            else:
                res += 1 * top1 +  (temp - 5) * c
        elif temp == 4:
            res += c + top1
        else:
            res += c + top2
        num = num % div
        return res, num
        

