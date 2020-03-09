class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        d1, d2 = dict(), dict()
        for i in range(len(s)):
            if d1.get(t[i], 0):
                if s[i] != d1[t[i]]:
                    return False
            else:
                d1[t[i]] = s[i]
            if d2.get(s[i], 0):
                if t[i] != d2[s[i]]:
                    return False
            else:
                d2[s[i]] = t[i]
        return True
