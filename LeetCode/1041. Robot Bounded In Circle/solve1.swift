class Solution {
    // 0: F
    // 1: L
    // 2: B
    // 3: R
    
    //      L
    // a, b -> -b, a
    //      B
    // a, b -> -a, -b
    //      R
    // a, b -> b, -a
    func add(_ va: (Int, Int), _ vb: (Int, Int)) -> (Int, Int) {
        (va.0 + vb.0, va.1 + vb.1)
    }
    
    func getNextDir(_ dir: Int, _ chDir: Int) -> Int {
        switch chDir {
            case 0: return dir
            case 1: return [1, 2, 3, 0][dir]
            case 2: return [2, 3, 0, 1][dir]
            case 3: return [3, 0, 1, 2][dir]
            default: return dir
        }
    }
    
    func getNext(_ v: (Int, Int), _ chDir: Int) -> (Int, Int) {
        let (a, b) = v
        switch chDir {
            case 0: return (a, b)
            case 1: return (-b, a)
            case 2: return (-a, -b)
            case 3: return (b, -a)
            default: return (0, 0)
        }
    }
    
    func toVec(_ instructions: String) -> ((Int, Int), Int) {
        var v = (0, 0)
        var dir = 0
        for s in instructions {
            switch s {
                case "G": 
                    v = add(v, [(0, 1), (-1, 0), (0, -1), (1, 0)][dir])
                case "L": 
                    dir = [1, 2, 3, 0][dir]
                case "R": 
                    dir = [3, 0, 1, 2][dir]
                default:
                    break
            }
            // print("After \(s) -> \(v) \(dir)")
        }
        
        return (v, dir)
    }
    
    func isRobotBounded(_ instructions: String) -> Bool {
        var ((sx, sy), dir) = toVec(instructions)
        // print("(\(sx), \(sy)) \(dir)")
        if sx == 0 && sy == 0 { return true }
        var totalx = sx
        var totaly = sy
        var ndir = dir
        while true {
            let (nx, ny) = getNext((sx, sy), ndir)
            // print("\((nx, ny)) \(ndir)")
            if nx == sx && ny == sy { break }
            totalx += nx
            totaly += ny
            ndir = getNextDir(ndir, dir)   
        }
        
        return totalx == 0 && totaly == 0
    }
}