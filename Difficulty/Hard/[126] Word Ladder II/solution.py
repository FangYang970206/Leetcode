from collections import deque

class Solution:
    def __init__(self):
        self.wordList = dict()
        self.ans = []
        self.visited = dict()
        self.level = 1
        self.minLevel = 2 ** 31 - 1

    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        for word in wordList:
            self.wordList[word] = 0
        q = deque()
        q.append([beginWord])
        
        while q:
            path = q.popleft()

            if len(path) > self.level:
                for w in self.visited.keys():
                    if self.wordList.get(w) is not None:
                        self.wordList.pop(w)
                if len(path) > self.minLevel:
                    break
                else:
                    self.level = len(path)

            lastWord = path[-1]
            
            self.addNeighboursToQ(lastWord, path, q, endWord)
        return self.ans
    
    def addNeighboursToQ(self, curr, path, q, endWord):
        for i in range(len(curr)):
            for j in range(26):
                new_str = curr[:i] + chr(ord('a') + j) + curr[i+1:]
                if self.wordList.get(new_str) is not None:
                    newpath = path[:]
                    newpath.append(new_str)
                    self.visited[new_str] = 0
                    if new_str == endWord:
                        self.minLevel = self.level
                        self.ans.append(newpath)
                        print(self.ans)
                    else:
                        q.append(newpath)
        