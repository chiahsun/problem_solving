class Solution {
    func validMountainArray(_ arr: [Int]) -> Bool {
        let N = arr.count
        var i = 0
        while i+1 < N && arr[i] < arr[i+1] {
            i += 1
        }
        if i < 1 || i == N-1 { return false }
        while i+1 < N && arr[i] > arr[i+1] {
            i += 1
        }
        return i == N-1
    }
}