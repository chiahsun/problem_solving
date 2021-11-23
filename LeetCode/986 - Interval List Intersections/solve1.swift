class Solution {
    func intervalIntersection(_ firstList: [[Int]], _ secondList: [[Int]]) -> [[Int]] {
        var points: [Int] = []
        var ans: [[Int]] = []
        var (i, k) = (0, 0)
        var dp: [Int] = []
        var start = -1
        while i < firstList.count && k < secondList.count {
            var candidates = [firstList[i][0], firstList[i][1], secondList[k][0], secondList[k][1]].filter { points.isEmpty || $0 > points.last! }
            
            let minVal = candidates.min()!
            points.append(minVal)
            dp.append(0)
            if start == -1 && minVal <= firstList[i][1] && minVal <= secondList[k][1] && minVal >= firstList[i][0] && minVal >= secondList[k][0] {
                start = minVal
            }
            
            if minVal == firstList[i][1] {
                if start != -1 {
                    ans.append([start, firstList[i][1]])    
                    start = -1
                }
                i += 1   
            }
            if minVal == secondList[k][1] {
                if start != -1 {
                    ans.append([start, secondList[k][1]])    
                    start = -1
                }
                k += 1
            }
        }
        
        return ans
    }
}