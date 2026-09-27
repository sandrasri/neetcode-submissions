class MyQueue:

    def __init__(self):
        self.leftstack = []

    def push(self, x: int) -> None:
        self.leftstack.append(x)

    def pop(self) -> int:
        return self.leftstack.pop(0)

    def peek(self) -> int:
        return self.leftstack[0]
        
    def empty(self) -> bool:
        if self.leftstack:
            return False
        return True
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()