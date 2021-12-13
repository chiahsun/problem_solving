func getDigits(_ a: Int, _ pos: Int) -> Int {
    var b = abs(a)
    for _ in 0..<pos { b /= 10 }
    return b%10
}

class Solution {
    func sortArray(_ nums: [Int]) -> [Int] {
        var nums = nums
        radixSort(&nums, 4)
        return nums.filter { $0 < 0 }.reversed() + nums.filter { $0 >= 0 }
    }
    
    func radixSort(_ nums: inout [Int], _ pos: Int) {
        radixSortHelper(&nums, 4, 0, nums.count)
    }
    
    func radixSortHelper(_ nums: inout [Int], _ pos: Int, _ lo: Int, _ hi: Int) {
        let R = 10
        var aux = Array(repeating: 0, count: hi-lo)
        var cnt = Array(repeating: 0, count: R+1)
        for i in lo..<hi {
            let d = getDigits(nums[i], pos)
            cnt[d+1] += 1
        }
        for i in 1...R {
            cnt[i] += cnt[i-1]
        }
        for i in lo..<hi {
            let a = nums[i]
            let d = getDigits(a, pos)
            aux[cnt[d]] = a
            cnt[d] += 1
        }
        for i in lo..<hi {
            nums[i] = aux[i-lo]
        }
        if pos > 0 {
            for r in 0..<R where cnt[r] > 0 {
                radixSortHelper(&nums, pos-1, lo+(r == 0 ? 0 : cnt[r-1]), lo+cnt[r])
            }
        }
    }
}