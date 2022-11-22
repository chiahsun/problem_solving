class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        d = defaultdict(int)
        for wd in words:
            d[wd] += 1
        def my_cmp(a, b):
            if d[a] != d[b]:
                return -1 if d[a] > d[b] else 1
            if a != b:
                return -1 if a < b else 1
            return 0
        a = list(d.keys())
        a.sort(key=cmp_to_key(my_cmp))
        return a[:k]
