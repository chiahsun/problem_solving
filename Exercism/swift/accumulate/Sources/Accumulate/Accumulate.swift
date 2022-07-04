//Solution goes in Sources
extension Array {
    func accumulate<ResultType>(_ fn: (Element) -> ResultType) -> [ResultType] {
        var res: [ResultType] = []
        res.reserveCapacity(self.count)
        for elem in self {
            res.append(fn(elem))
        }
        
        return res
    }
}
