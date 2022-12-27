class Solution {
    func intervalIntersection(_ firstList: [[Int]], _ secondList: [[Int]]) -> [[Int]] {
        var (i, k) = (0, 0)
        var ans: [[Int]] = []
        while i < firstList.count && k < secondList.count {
            let (A, B) = (firstList[i], secondList[k])
            var begin = max(A[0], B[0])
            var end = min(A[1], B[1])
            if begin <= end  {
                ans.append([begin, end])
            }
            if end == A[1] { i += 1 }
            if end == B[1] { k += 1 }
        }
        return ans
    }
}