class Solution:
    def simplifyPath(self, path: str) -> str:
        simp, dot_flag, path_chars = "", False, ['/']
        for i in range(1, len(path)):
            if path[i] == '/':
                dot_flag = False
                if path_chars[-1] != '/':
                    path_chars.append(path[i])
            elif path[i] == '.':
                if dot_flag:
                    path_chars.append('.')
                elif i + 1 < len(path):
                    if path[i + 1] == '.':
                        if i + 2 < len(path) and path[i + 2] != '/':
                            if path[i + 2] == '.':
                                dot_flag = True
                            path_chars.append(path[i])
                        elif len(path_chars) != 1:
                            path_chars.pop()
                            while path_chars[-1] != '/':
                                path_chars.pop()
                    elif path[i + 1] != '/':
                        path_chars.append(path[i])
            else:
                dot_flag = False
                path_chars.append(path[i])
        if path_chars[-1] == '/' and len(path_chars) != 1:
            path_chars.pop()
        for c in path_chars:
            simp += c
        return simp
        