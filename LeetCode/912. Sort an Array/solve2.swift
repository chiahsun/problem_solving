func getDigits(_ a: Int, _ pos: Int) -> Int {
    var b = abs(a)
    for _ in 0..<pos { b /= 10 }
    return b%10
}

class Solution {
    func sortArray(_ nums: [Int]) -> [Int] {
        var nums = nums
        radixSort(&nums)
        return nums
    }
    
    func radixSort(_ nums: inout [Int]) {
        for i in 0...4 {
            radixSortHelper(&nums, i)
        }
        nums = nums.filter { $0 < 0 }.reversed() + nums.filter { $0 >= 0 }
    }
    
    func radixSortHelper(_ nums: inout [Int], _ pos: Int) {
        let R = 10
        var aux = Array(repeating: 0, count: nums.count)
        var cnt = Array(repeating: 0, count: R+1)
        for a in nums {
            cnt[getDigits(a, pos)+1] += 1
        }
        for i in 1...R {
            cnt[i] += cnt[i-1]
        }
        for i in 0..<nums.count {
            let a = nums[i]
            let d = getDigits(a, pos)
            aux[cnt[d]] = a
            cnt[d] += 1
        }
        nums = aux
    }
}