class Solution {
    func groupAnagrams(_ strs: [String]) -> [[String]] {
        var d: [String: [String]] = [:]
        for s in strs { 
            d[String(s.sorted()), default: []].append(s)
        }
        return Array(d.values)
    }
}