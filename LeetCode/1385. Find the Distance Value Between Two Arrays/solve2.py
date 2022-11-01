class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        s1, s2 = set(arr1), set(arr2)
        arr1.extend(arr2)
        arr1.sort()

        ans, N = 0, len(arr1)
        for i in range(N):
            cur = arr1[i]
            if cur in s1:
                ok = True
                k = i
                while k >= 0:
                    if cur - arr1[k] > d:
                        break
                    if arr1[k] in s2:
                        ok = False
                        break
                    k -= 1
                k = i+1
                while ok and k < N:
                    if arr1[k] - cur > d:
                        break
                    if arr1[k] in s2:
                        ok = False
                        break
                    k += 1
                if ok:
                    ans += 1
        return ans 
