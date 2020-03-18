from collections import deque

class Solution:
    def canFinish(self, numCourses, prerequisites):
        graph = []
        for _ in range(numCourses):
            graph.append([])
        indegrees = [0] * numCourses
        for v in prerequisites:
            graph[v[1]].append(v[0])
            indegrees[v[0]] += 1
        q = deque()
        for i in range(numCourses):
            if indegrees[i] == 0:
                q.append(i)
        while q:
            curr = q.popleft()
            numCourses -= 1
            for i in graph[curr]:
                indegrees[i] -= 1
                if indegrees[i] == 0:
                    q.append(i)
        return numCourses == 0