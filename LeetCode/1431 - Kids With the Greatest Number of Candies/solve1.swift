class Solution {
    func kidsWithCandies(_ candies: [Int], _ extraCandies: Int) -> [Bool] {
        let greatest = candies.max() ?? 0
        
        // https://developer.apple.com/documentation/swift/array/3017522-map
        return candies.map { $0 + extraCandies >= greatest }
    }
}