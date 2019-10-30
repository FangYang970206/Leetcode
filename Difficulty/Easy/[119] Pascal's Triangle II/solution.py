class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0: return [1]
        if rowIndex == 1: return [1, 1]
        if rowIndex == 2: return [1, 2, 1]
        res = [0] * (rowIndex + 1)
        res[0], res[1], res[2] = 1, 2, 1
        for i in range(3, rowIndex + 1):
            prev, tmp = 1, 0
            for j in range(1, i):
                tmp = res[j] + prev
                prev = res[j]
                res[j] = tmp
            res[i] = 1
        return res