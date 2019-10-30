class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0: return []
        if numRows == 1: return [[1]]
        if numRows == 2: return [[1], [1, 1]]
        res = [[1], [1, 1]]
        for i in range(3, numRows+1):
            tmp = [0] * i
            for j in range(1, i + 1):
                if j == 1 or j == i:
                    tmp[j - 1] = 1
                else:
                    tmp[j - 1] = res[i - 2][j - 1] + res[i - 2][j - 2]
            res.append(tmp)
        return res