class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        # print('nums: ', nums)
        d, N = defaultdict(list), len(nums)
        # 2 2 3 3 target= 12
        for i in range(N-1):
            if i-2 >= 0 and nums[i-2] == nums[i-1] == nums[i]:
                continue
            for k in range(i+1, N):
                if  k-2 >= i+1 and nums[k-2] == nums[k-1] == nums[k]:
                    continue
                cur = nums[i] + nums[k]
                d[cur].append([i, k])
                # print('cur: ', cur, ' pos: ', [i, k])
        # print(d)
        res = set()
        for s1 in d.keys():
            s2 = target - s1
            if s2 < s1 and s2 in d:
                for a in d[s1]:
                    for b in d[s2]:
                        if b[0] not in a and b[1] not in a:
                            # print(a, b, ' ', s1, s2)
                            res.add(tuple(sorted(map(lambda i: nums[i], a + b))))
            elif s1 == s2:
                dd = d[s1]
                for i in range(len(dd)-1):
                    a = dd[i]
                    for k in range(i+1, len(dd)):
                        b = dd[k]
                        if b[0] not in a and b[1] not in a:
                            # print(a, b, ' ', s1, s2)
                            res.add(tuple(sorted(map(lambda i: nums[i], a + b))))

        return list(res)
