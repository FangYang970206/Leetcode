class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        S = []
        for token in tokens:
            if token == "+":
                S.append(S.pop() + S.pop())
            elif token == "-":
                num2 = S.pop()
                num1 = S.pop()
                S.append(num1 - num2)
            elif token == "*":
                S.append(S.pop() * S.pop())
            elif token == "/":
                num2 = S.pop()
                num1 = S.pop()
                S.append(int(num1 / num2))
            else:
                S.append(int(token))
        return S[0]