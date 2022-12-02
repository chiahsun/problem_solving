# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        def traversal(p):
            if isinstance(p, list):
                for a in p:
                    yield from traversal(a)
            elif not p.isInteger():
                for a in p.getList():
                    yield from traversal(a)
            else:
                yield p.getInteger()
               
        self.gen = traversal(nestedList)
        self.buf = None
    
    def next(self) -> int:
        res = self.buf
        if self.buf is not None:
            
            self.buf = None
            return res
        return next(self.gen)
        
    def hasNext(self) -> bool:
        if self.buf is not None:
            return True
        try:
            self.buf = next(self.gen)
        except:
            return False

        return True
         

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
