class Solution:
    def minWindow(self, s: str, t: str) -> str:
        t_map = [0] * 128
        for c in t:
            t_map[ord(c)] += 1
        begin, end, min_len, min_begin, counter, s_size = 0, 0, 2**31, 0, len(t), len(s)
        while end < s_size:
            if t_map[ord(s[end])] > 0:
                counter -= 1
            t_map[ord(s[end])] -= 1
            end += 1
            while counter == 0:
                if end - begin < min_len:
                    min_begin = begin
                    min_len = end - begin
                t_map[ord(s[begin])] += 1
                if t_map[ord(s[begin])] > 0:
                    counter += 1
                begin += 1
        if min_len != 2**31:
            return s[min_begin : min_begin+min_len]
        return ""