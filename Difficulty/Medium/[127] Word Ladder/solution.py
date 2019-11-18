from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList: return 0
        wordDict, visited = dict(), []
        for w in wordList:
            wordDict[w] = 0
        if wordDict.get(beginWord) is not None: wordDict.pop(beginWord)
        level, res, visited_begin = 1, 0, 0
        q = deque()
        q.append(beginWord)
        while q:
            size = len(q)
            for i in range(size):
                curr = q.popleft()
                for j in range(visited_begin, len(visited)):
                    wordDict.pop(visited[j])
                visited_begin = len(visited)    
                res = self.addNeighboursToQ(curr, wordDict, visited, q, endWord, level)
                if res != 0: return res
            level += 1
        return 0
    
    def addNeighboursToQ(self, curr, wordSet, visited, q, endWord, level):
        for s in wordSet:
            if self.isOneCharDiff(curr, s):
                q.append(s)
                visited.append(s)
                if s == endWord:
                    return level + 1
        return 0

    def isOneCharDiff(self, s1, s2):
        num = 0
        for i in range(len(s1)):
            if s1[i] != s2[i]: num += 1
            if num > 1: return False
        return num == 1