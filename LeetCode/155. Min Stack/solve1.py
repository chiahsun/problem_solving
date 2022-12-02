class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.v = []
        self.min_now = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.v.append(x)
        self.min_now.append(x if not self.min_now or self.min_now[-1] > x else self.min_now[-1])
        

    def pop(self):
        """
        :rtype: void

        Reference
          http://stackoverflow.com/questions/11277432/how-to-remove-a-key-from-a-dictionary
        """
        x = self.v[-1]
        self.v.pop()
        self.min_now.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.v[-1]
        

    def getMin(self):
        """
        :rtype: int

        Reference
          http://stackoverflow.com/questions/3282823/get-key-with-the-least-value-from-a-dictionary
        """
        return self.min_now[-1] 
        


st = MinStack()
st.push(-2)
st.push(0)
st.push(-3)
print(st.getMin())
st.pop()
print(st.top())
print(st.getMin())
