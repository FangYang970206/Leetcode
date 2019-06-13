#
# @lc app=leetcode id=38 lang=python3
#
# [38] Count and Say
#
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        if n == 2:
            return '11'
        s = '11'
        for _ in range(n - 2):
            temp, num, c = '', 0, ''
            for elem in s:
                if c and elem == c:
                    num += 1
                elif c and elem != c:
                    temp += str(num) + c
                    num = 1
                    c = elem
                else:
                    num = 1
                    c = elem
            temp += str(num) + c
            s = temp
        return s