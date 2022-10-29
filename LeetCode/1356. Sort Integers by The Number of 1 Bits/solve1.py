class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        def nbits(a):
            cnt = 0
            while a > 0:
                cnt += 1
                a &= (a - 1)
            return cnt

        def list_cmp(a, b):
            if a == b:
                return 0
            if nbits(a) != nbits(b):
                return -1 if nbits(a) < nbits(b) else 1
            return -1 if a < b else 1

        arr.sort(key=cmp_to_key(list_cmp))
        return arr
