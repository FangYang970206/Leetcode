class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        if not s:
            return False
        if len(s) == 1:
            return s[0] >= '0' and s[0] <= '9'
        if s[0] == '-' or s[0] == '+':
            s = s[1:]
        try:
            e_pos = s.index('e')
            if e_pos == len(s) - 1 or e_pos == 0:
                return False
            else:
                n = s[e_pos + 1] == '-' or s[e_pos + 1] == '+'
                if e_pos + 1 == len(s) - 1 and n == 1:
                    return False
                else:
                    return self._checkNumber(s[:e_pos], False) \
                           and self._checkNumber(s[e_pos+1+n:], True)
        except ValueError:
            return self._checkNumber(s, False)

    def _checkNumber(self, s: str, dot_exist: bool) -> bool:
        if len(s) == 1 and s[0] == '.':
            return False
        for i in range(len(s)):
            if s[i] >= '0' and s[i] <= '9':
                continue
            elif s[i] == '.' and not dot_exist:
                dot_exist = True
            else:
                return False
        return True
        