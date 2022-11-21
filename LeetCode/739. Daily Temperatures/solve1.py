class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        st, res = [], [0] *  len(temperatures)
        for i in range(len(temperatures)):
            cur = temperatures[i]
            while st and cur > temperatures[st[-1]]:
                res[st[-1]] = i-st[-1]
                st.pop()
            st.append(i)
        return res
            
