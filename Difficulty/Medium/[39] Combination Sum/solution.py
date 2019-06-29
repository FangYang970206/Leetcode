class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()
        self.dfs(res, candidates, target, [], 0)
        return res
        
    def dfs(self, res, candidates, target, combination, begin):
        if target < 0:
            return
        if target == 0:
            res.append(combination)
            return
        for i in range(begin, len(candidates)):
            self.dfs(res, candidates, target - candidates[i], combination+[candidates[i]], i)