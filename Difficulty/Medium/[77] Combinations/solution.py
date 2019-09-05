class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res, elem = [], []
        self.combine_helper(n, k, 1, elem, res)
        return res
    
    def combine_helper(self, n, k, begin, elem, res):
        if len(elem) == k:
            res.append(elem[:])
            return
        for i in range(begin, n+1):
            elem.append(i)
            if elem[0] > n - k + 1:
                break
            self.combine_helper(n, k, i+1, elem, res)
            elem.pop()

