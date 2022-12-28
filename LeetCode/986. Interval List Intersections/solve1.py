class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        res = []
        if not firstList or (secondList and secondList[0][0] < firstList[0][0]):
            firstList, secondList = secondList, firstList
        begin, end = firstList[0][0], firstList[0][1]
        ll = [firstList[1:], secondList]
        compareList = 1
        while ll[compareList]:
            if end <= ll[compareList][0][0]:
                if end == ll[compareList][0][0]:
                    res.append([end, end])
                begin, end = ll[compareList][0][0], ll[compareList][0][1]
                ll[compareList] = ll[compareList][1:]
                compareList = 1-compareList
            elif begin >= ll[compareList][0][1]:
                if begin == ll[compareList][0][1]:
                    res.append([begin, begin])
                ll[compareList] = ll[compareList][1:]
            else:
                if end >= ll[compareList][0][1]:
                    res.append([max(begin, ll[compareList][0][0]), ll[compareList][0][1]])
                    ll[compareList] = ll[compareList][1:]
                else:
                    res.append([max(begin, ll[compareList][0][0]), end])
                    begin, end = ll[compareList][0][0], ll[compareList][0][1]
                    ll[compareList] = ll[compareList][1:]
                    compareList = 1-compareList
        return res
