# can be done using 2 stacks
# one that stores every single element 
# and one monotonic stack that will always have the minimum on top 

class MinStack:

    def __init__(self):
        self.stack = []
        self.monotonic_stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if len(self.monotonic_stack) > 0: 
            if val <= self.monotonic_stack[-1]: 
                self.monotonic_stack.append(val)
        else: self.monotonic_stack.append(val)

    def pop(self) -> None:
        popped = self.stack.pop()
        if popped == self.monotonic_stack[-1]: self.monotonic_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.monotonic_stack[-1]
