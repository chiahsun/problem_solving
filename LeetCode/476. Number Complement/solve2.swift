class Solution {
    func findComplement(_ num: Int) -> Int {
        var mask = 1
        while mask < num {  
            mask <<= 1
            mask |= 1
        }
        return num ^ mask
    }
}