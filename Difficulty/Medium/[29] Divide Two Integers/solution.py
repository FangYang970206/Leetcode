#
# @lc app=leetcode id=29 lang=python3
#
# [29] Divide Two Integers
#
class Solution:
    def divide(self, dividend: int,divisor: int) -> int:
        #被除数为1，返回除数
        if divisor == 1:
            return dividend
        #被除数为-1，且除数为最小值，返回最大值
        if divisor == -1 and dividend ==-2**31:
            return 2**31 - 1
        #被除数为-1，且除数不为最小值，返回负的除数
        if divisor == -1 and dividend !=-2**31:
            return -dividend
        res, temp, m= 0, 0, 0
        #除数与被除数同号时，sign为0，否则为1
        sign = (dividend > 0) ^ (divisor> 0)
        #取正整数
        dvd, dvs = abs(dividend), abs(divisor)
        #当除数小于被除数时退出循环
        while dvd >= dvs:
            # 初始化temp和m
            temp, m = dvs, 1
            # 循环查找最大不超过dvd的m
            while temp << 1 <= dvd:
                # temp左移一个单位
                temp <<= 1
                m <<= 1
            #减去temp，得到新的temp
            dvd -= temp
            #加上m
            res += m
        #根据sign得到res
        return -res if sign else res

