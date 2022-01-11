import sys
import operator

cnts = [0]
for _ in range(100):
    cnts.append(2*cnts[-1] + 1)

def binarySearchLeqPos(nums, target):
    if target >= nums[-1]:
        return len(nums)-1
    if target <= nums[0]:
        return 0
    i = 0
    k = len(nums)-1

    while i < k:
        mid = (i+k+1)//2
        mid_val = nums[mid]
        if mid_val > target:
            k = mid-1
        else:
            i = mid
    return i

def solve(cnts, n, m, one_pos):
    k = binarySearchLeqPos(cnts, m)
    res = [0, 0, 0]
    res[one_pos] = n-k
    k_pos = (one_pos + (1 if k % 2 == 1 else 2)) % 3
    res[k_pos] = k
    m -= cnts[k]
    if m == 0:
        return res
    next_largest_pos = ((3 - k_pos - one_pos) % 3 + 3) % 3
    res[one_pos] -= 1
    res[next_largest_pos] += 1
    m -= 1
    if m == 0:
        return res
    smaller_res = solve(cnts, k, m, k_pos)
    res[k_pos] -= k
    return list(map(operator.add, res, smaller_res))

# print(cnts)

for line in sys.stdin:
    params = list(map(int, line.rstrip('\n').split(" ")))
    N, M = params[0], params[1]
    if N == 0 and M == 0:
        break
    # print(N, M)
    print(' '.join(map(str, solve(cnts, N, M, 0))))