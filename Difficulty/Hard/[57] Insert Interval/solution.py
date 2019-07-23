class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        if not intervals:
            res.append(newInterval)
            return res
        if not newInterval:
            return intervals
        insert_interval = []
        for interval in intervals:
            if len(insert_interval) == 0:
                if interval[1] < newInterval[0]:
                    res.append(interval)
                else:
                    if interval[0] > newInterval[0]:
                        if newInterval[1] > interval[1]:
                            insert_interval.append(newInterval[0])
                        elif newInterval[1] < interval[0]:
                            insert_interval = [newInterval[0], newInterval[1]]
                            res.append(insert_interval)
                            res.append(interval)
                        else:
                            insert_interval = [newInterval[0], interval[1]]
                            res.append(insert_interval)
                    else:
                        insert_interval.append(interval[0])
                        if newInterval[1] < interval[1]:
                            insert_interval.append(interval[1])
                            res.append(insert_interval)
            elif len(insert_interval) == 1:
                if interval[0] > newInterval[1]:
                    insert_interval.append(newInterval[1])
                    res.append(insert_interval)
                    res.append(interval)
                else:
                    if interval[0] <= newInterval[1] and interval[1] > newInterval[1]:
                        insert_interval.append(interval[1])
                        res.append(insert_interval)
            else:
                res.append(interval)
        if len(insert_interval) == 0:
            res.append(newInterval)
        if len(insert_interval) == 1:
            insert_interval.append(newInterval[1])
            res.append(insert_interval)
        return res                               