class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        st = []
        for a in asteroids:
            if a > 0 or not st or st[-1] < 0:
                st.append(a)
            else:
                while st and st[-1] > 0 and st[-1] < -a:
                    st.pop()
                if st and st[-1] > 0:
                    if st[-1] == -a:
                        st.pop()
                else:
                    st.append(a)
        return st

