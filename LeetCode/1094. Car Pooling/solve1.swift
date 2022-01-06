// 1   5
// -----
//   2
//   3    7
//   ------
//      3
class Solution {
    func carPooling(_ trips: [[Int]], _ capacity: Int) -> Bool {
        let trips = trips.sorted(by: { a, b in
            a[1] < b[1]
        })
        // print(trips)
        var s: Set<Int> = []
        trips.forEach { s.insert($0[1]); s.insert($0[2]); }
        let stops: [Int] = Array(s).sorted()
        // print(stops)
        
        var capacity = capacity
        var m: [Int: Int] = [:]
        
        var posTrip = 0
        for stop in stops {
            if let mapped = m[stop] {
                capacity += mapped
                m[stop] = nil
            }
            // print("stop: \(stop) capacity: \(capacity)")
            while posTrip < trips.count, 
                  case let curTrip = trips[posTrip],
                  curTrip[1] == stop {
                let passengers = curTrip[0]
                capacity -= passengers
                m[curTrip[2], default: 0] += passengers
                posTrip += 1
                if capacity < 0 { return false }
            }
            if posTrip == trips.count {
                break
            }
        }
 
        return true
    }
}