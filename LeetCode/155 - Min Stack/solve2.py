class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.v, self.m = [], []
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if not self.m or x < self.m[-1][0]:
            self.m.append([x, len(self.v)])
        self.v.append(x)
        
    
    def pop(self):
        """
        :rtype: void
        """
        x = self.v[-1]
        self.v.pop()
        if len(self.m) > 0 and self.m[-1][1] >= len(self.v):
            self.m.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.v[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.m[-1][0]


st = MinStack()
st.push(-2)
st.push(0)
st.push(-3)
print(st.getMin())
st.pop()
print(st.top())
print(st.getMin())

