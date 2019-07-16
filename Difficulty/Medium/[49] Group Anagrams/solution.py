class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res, records = [], dict()
        for s in strs:
            t = s
            t = sorted(t)
            t = ''.join(t)
            if records.get(t):
                records[t].append(s)
            else:
                records[t] = [s]
        for values in records.values():
            res.append(values)
        return res