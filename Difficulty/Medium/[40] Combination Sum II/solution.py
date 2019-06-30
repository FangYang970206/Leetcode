class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
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
            if i != begin and candidates[i] == candidates[i-1]:
                continue
            self.dfs(res, candidates, target - candidates[i], combination+[candidates[i]], i+1)