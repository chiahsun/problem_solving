func square(_ point: [Int]) -> Int { point[0]*point[0] + point[1]*point[1] }

class Solution {
    func kClosest(_ points: [[Int]], _ k: Int) -> [[Int]] {
        return Array(points.sorted { square($0) < square($1) } [..<k])
    }
}