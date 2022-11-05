class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        var i = 0
        var k = numbers.count-1
        while i < k {
            var sum = numbers[i] + numbers[k]
            if (sum == target) { return [i+1, k+1] }
            if (sum > target) { k -= 1}
            else              { i += 1}
        }
        return []
    }
}