class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.dict = dict()
        self.minimum = 2 ** 31 - 1

    def push(self, x: int) -> None:
        self.stack.append(x)
        self.minimum = min(x, self.minimum)
        if not self.dict.get(x, None):
            self.dict[x] = [self.minimum]
        else:
            self.dict[x].append(self.minimum)

    def pop(self) -> None:
        if len(self.dict[self.stack[-1]]) != 1:
            self.dict[self.stack[-1]].pop()
        else:
            self.dict.pop(self.stack[-1])
        self.stack.pop()
        if self.stack:
            self.minimum = self.dict[self.stack[-1]][-1]
        else:
            self.minimum = 2 ** 31 - 1

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minimum