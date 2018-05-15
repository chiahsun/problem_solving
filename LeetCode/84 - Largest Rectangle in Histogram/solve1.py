class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        def getAreaFromStack(st, h, pos):
            max_area = 0
            last = None
            while st:
                if st[-1][0] > h:
                    last = st[-1]
                    max_area = max(max_area, st[-1][0] * (pos - st[-1][1]))
                    st.pop()
                else:
                    break
            if last is None:
                st.append([h, pos])
            else:
                st.append([h, last[1]])
            return max_area
            
        st = [] # [h, pos]
        max_area = 0
        for i in range(len(heights)):
            h = heights[i]
            max_area = max(max_area, getAreaFromStack(st, h, i))
        max_area = max(max_area, getAreaFromStack(st, 0, len(heights)))
        return max_area

