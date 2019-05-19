#
# @lc app=leetcode id=30 lang=python3
#
# [30] Substring with Concatenation of All Words
#
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []
        counts = dict()
        for word in words:
            counts[word] = counts.get(word, 0) + 1
        n, num, word_len, indexs = len(s), len(words), len(words[0]), []
        for i in range(n - num * word_len + 1):
            seen = dict()
            j = 0
            while j < num:
                word = s[i + j * word_len: i + (j + 1) * word_len]
                if word in counts.keys():
                    seen[word] = seen.get(word, 0) + 1
                    if seen[word] > counts[word]:
                        break
                else:
                    break
                j += 1
            if j == num:
                indexs.append(i)
        return indexs