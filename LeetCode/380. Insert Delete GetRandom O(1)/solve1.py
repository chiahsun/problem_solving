class RandomizedSet:

    def __init__(self):
        self.A, self.D = [], {}

    def insert(self, val: int) -> bool:
        if val in self.D:
            return False
        pos = len(self.A)
        self.A.append(val)
        self.D[val] = pos
        return True

    def remove(self, val: int) -> bool:
        if val not in self.D:
            return False
        pos = self.D[val]
        last_pos_val = self.A[-1]
        del self.D[val]
        if pos != len(self.A)-1:
            self.A[pos], self.A[-1] = self.A[-1], self.A[pos]
            self.D[last_pos_val] = pos
        self.A.pop()
        return True
        
    def getRandom(self) -> int:
        return self.A[randint(0, len(self.A)-1)]
        
# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
