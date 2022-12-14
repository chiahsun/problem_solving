class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        # Note that A only contains distinct elements
        def binary_search(ary, target, offset=0, incr=True):
            # import bisect # After python 3.10 https://docs.python.org/zh-tw/3/library/bisect.html
            # key_f = (lambda x: x) if incr else (lambda x: -x)
            # pos = bisect.bisect_left(ary, target, key=key_f)
            # pos + offset if (pos < len(ary) and ary[pos] == target) else -1
            # print('ary: ', ary, ' incr: ', incr)
            lo, hi = 0, len(ary)-1
            while lo <= hi:
                mid = (lo+hi)//2
                mid_val = ary[mid]
                if mid_val == target:
                    return offset+mid
                if (target > mid_val) ^ incr:
                    hi = mid-1
                else:
                    lo = mid+1
            return -1

        def solve_rec(A, B, offset):
            if not A:
                return -1
            lo, hi = 0, len(A) - 1
            mid = (lo + hi) // 2
            mid_val = A[mid]
            if mid_val == B:
                return mid + offset
            if lo == hi:
                return -1
            if B > mid_val:
                if A[mid + 1] > mid_val:
                    return solve_rec(A[mid + 1:], B, offset + mid + 1)
                else:
                    return solve_rec(A[:mid], B, offset)
            else:
                if A[mid + 1] < mid_val:
                    return binary_search(A[mid + 1:], B, offset + mid + 1, False)
                else:
                    return binary_search(A[:mid], B, offset, True)

        return solve_rec(A, B, 0)