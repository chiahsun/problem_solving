class Solution {
    func checkIfExist(_ arr: [Int]) -> Bool {
        let N = arr.count
        for i in 0..<(N-1) {
            for k in (i+1)..<N {
                if arr[i] == 2*arr[k] || arr[k] == 2*arr[i] {
                    return true
                }
            }
        }
        return false
    }
}