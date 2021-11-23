class Solution {
    func intervalIntersection(_ firstList: [[Int]], _ secondList: [[Int]]) -> [[Int]] {
        var (i, k) = (0, 0)
        var ans: [[Int]] = []
        while i < firstList.count && k < secondList.count {
            let (A, B) = (firstList[i], secondList[k])

            // |--|
            //   |--|
            if A[0] < B[0] {
                // |---|
                //       |---|
                if B[0] > A[1] {
                    i += 1
                } else {
                    // |---|
                    //   |-|
                    if B[1] <= A[1] {
                        ans.append([B[0], B[1]])    
                        k += 1
                    } else {
                        // |---|
                        //   |----|
                        ans.append([B[0], A[1]])    
                        i += 1
                    }
                }
            } else {
                if A[0] > B[1] {
                    k += 1
                } else {
                    if A[1] <= B[1] {
                        ans.append([A[0], A[1]])    
                        i += 1
                    } else {
                        ans.append([A[0], B[1]])    
                        k += 1
                    }
                }
            }
        }
        return ans
    }
}