class Solution:
    def reverseWords(self, s: str) -> str:
        if not s: return ""
        s_list = s.strip().split()
        res = ""
        for i in range(len(s_list) - 1, -1, -1):
            res += s_list[i]
            if i != 0:
                res += " "
        return res