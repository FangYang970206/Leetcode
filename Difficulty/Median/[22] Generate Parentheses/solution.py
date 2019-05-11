#
# @lc app=leetcode id=22 lang=python3
#
# [22] Generate Parentheses
#
class Solution1:
    def generateParenthesis(self, n: int) -> List[str]:
        def addParenthsis(l, s, a, b):
            if a == 0 and b == 0:
                l.append(s)
                return l
            if a > 0:
                addParenthsis(l, s + '(', a - 1, b + 1)
            if b > 0:
                addParenthsis(l, s + ')', a, b - 1)
            return l
        res = []
        return addParenthsis(res, '', n, 0)

#ref https://leetcode.com/problems/generate-parentheses/discuss/10110/Simple-Python-DFS-solution-with-explanation
class Solution2:
# @param {integer} n
# @return {string[]}
    def generateParenthesis(self, n):
        if not n:
            return []
        left, right, ans = n, n, []
        self.dfs(left,right, ans, "")
        return ans

    def dfs(self, left, right, ans, string):
        if right < left:
            return
        if not left and not right:
            ans.append(string)
            return
        if left:
            self.dfs(left-1, right, ans, string + "(")
        if right:
            self.dfs(left, right-1, ans, string + ")")