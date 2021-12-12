class Solution {
    func canPartition(_ nums: [Int]) -> Bool {
        var s: Set<Int> = [0]
        var newElements: [Int] = []
        var total = 0
        for a in nums {
            for prev in s {
                let elem = a + prev
                newElements.append(elem)
            }
            newElements.forEach { s.insert($0) }
            newElements.removeAll()
            total += a
        }
        return (total % 2 == 0) && s.contains(total/2)
    }
}