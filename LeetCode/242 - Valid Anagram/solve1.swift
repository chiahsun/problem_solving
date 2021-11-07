class Solution {
    func isAnagram(_ s: String, _ t: String) -> Bool {
        var ds: [Character: Int] = [:]
        var dt: [Character: Int] = [:]
        for c in s {
            ds[c, default: 0] += 1
        }
         for c in t {
            dt[c, default: 0] += 1
        }
        if ds.keys.count != dt.keys.count {
            return false
        }
        for k in ds.keys {
            if let cnt = dt[k],
               cnt == ds[k] {    
            } else {
                   return false
            }
        }
        return true
    }
}