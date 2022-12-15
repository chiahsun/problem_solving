class MinStack:
    def __init__(self):
        self.A, self.M = [], []

    
    # @param x, an integer
    def push(self, x):
        self.A.append(x)
        self.M.append(min(self.M[-1] if self.M else x, x))


    # @return nothing
    def pop(self):
        if self.A:
            self.A.pop(); self.M.pop()


    # @return an integer
    def top(self):
        return self.A[-1] if self.A else -1


    # @return an integer
    def getMin(self):
        return self.M[-1] if self.M else -1

