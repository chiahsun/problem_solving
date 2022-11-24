class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        st, res = [], [-1] * len(nums)
        for _ in range(2):
            for i in reversed(range(len(nums))):
                cur = nums[i]
                while st and cur >= st[-1]:
                    st.pop()
                if st:
                    res[i] = st[-1]
                st.append(cur)
        return res
