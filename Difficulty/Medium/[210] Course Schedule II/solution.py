class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        degrees, coursesOrder, graph = [0] * numCourses, [], []
        for i in range(numCourses):
            graph.append([])
        for pre in prerequisites:
            graph[pre[1]].append(pre[0])
            degrees[pre[0]] += 1
        while len(coursesOrder) < numCourses:
            index = numCourses
            for i in range(numCourses):
                if degrees[i] == 0:
                    coursesOrder.append(i)
                    index = i
                    degrees[i] = -1
                    break
            if index == numCourses and len(coursesOrder) < numCourses:
                return []
            else:
                for val in graph[index]:
                    degrees[val] -= 1
        return coursesOrder