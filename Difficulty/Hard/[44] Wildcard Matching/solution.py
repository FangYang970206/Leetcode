#
# @lc app=leetcode id=44 lang=python3
#
# [44] Wildcard Matching
#
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        sLen, pLen, i, j, sTrack, pTrack = len(s), len(p), 0, 0, -1, -1
        while i < sLen:
            if j < pLen and (s[i] == p[j] or p[j] == '?'):
                i += 1
                j += 1
            elif j < pLen and p[j] == '*':
                sTrack = i
                pTrack = j
                j += 1
            elif pTrack >= 0:
                j = pTrack + 1
                sTrack += 1
                i = sTrack
            else:
                return False
        while j < len(p) and p[j] == '*':
            j += 1
        return j == pLen
