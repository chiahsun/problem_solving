// [1,2,3,4,5]
// [3,4,5,1,2]
// [-2,-2,-2,3,3]

// [2,3,4]
// [3,4,3]
// [-1,1,-1]

// [8,2,1,4]
// [2,6,4,2]
// [6,-4,-3,2]
// (6+-4+-3+2) - (-4+-3) = 8
// The problem can be reduce to find largest accumulated sequence in a circular list which is combined of 2 sub problems.
// 1. Find largest accumulated sequence in a list
// 2. Find smallest accumulated sequence in a list(and total minus it)
// Then find max of 1, 2.

// [5,8,2,8]
// [6,5,6,6]
// [-1,3,-4,2]
class Solution {
    func canCompleteCircuit(_ gas: [Int], _ cost: [Int]) -> Int {
        var A = gas
        var total = 0
        for i in 0..<cost.count { 
            A[i] -= cost[i] 
            total += A[i]
        }
        guard total >= 0 else { return -1 }
        // print("A: \(A)")
        var maxVal = A[0], accMax = A[0], maxStartPos = 0, curMaxStartPos = 0
        var minVal = A[0], accMin = A[0], minEndPos = 0
        for i in 1..<A.count {
            let cur = A[i]
            // print(" > process \(cur) with acc: \(accMax)")
            if accMax >= 0 {
                if accMax + cur > maxVal {
                    maxStartPos = curMaxStartPos
                    // print("Update maxStartPos to \(maxStartPos)")
                    maxVal = accMax + cur
                }
                // maxVal = max(maxVal, accMax + cur)
                accMax = max(cur, accMax + cur)
            } else {
                curMaxStartPos = i
                // print("Change curMaxStartPos to \(curMaxStartPos)")
                if cur > maxVal {
                    maxStartPos = curMaxStartPos
                    // print("Update maxStartPos to \(maxStartPos)")
                }
                maxVal = max(maxVal, cur)
                accMax = cur
            }
            if accMin <= 0 {
                if accMin + cur < minVal {
                    minEndPos = i
                    // print("Update minEndPos to \(minEndPos)")
                    minVal = accMin + cur
                }
                // minVal = min(minVal, accMin + cur)
                accMin = min(cur, accMin + cur)
            } else {
                if cur < minVal {
                    minVal  = cur
                    minEndPos = i
                    // print("Update minEndPos to \(minEndPos)")
                }
                // minVal = min(minVal, cur)
                accMin = cur
            }
        }
        let circularMax = max(maxVal, total-minVal)
        // print(circularMax)
        var ans = maxStartPos
        // print("Max start pos: \(maxStartPos) Min end pos: \(minEndPos)")
        if maxVal < total-minVal {
            ans = (minEndPos+1) % A.count
        }
        return ans
    }
}