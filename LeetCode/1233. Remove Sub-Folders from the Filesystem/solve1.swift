class Solution {
    func isSubFolder(_ subFolder: String, _ parentFolder: String) -> Bool {
        guard subFolder.count > parentFolder.count else { return false }
        guard subFolder.hasPrefix(parentFolder) else { return false }
        let index = subFolder.index(subFolder.startIndex, offsetBy: parentFolder.count)
        return subFolder[index] == "/"
    }
    
    func removeSubfolders(_ folder: [String]) -> [String] {
        var ans: [String] = []
        let folder = folder.sorted()
        var i = 0
        while i < folder.count {
            let now = folder[i]
            ans.append(now)
            i += 1
            while i < folder.count && isSubFolder(folder[i], now) {
                i += 1
            }
        }
        return ans
    }
}