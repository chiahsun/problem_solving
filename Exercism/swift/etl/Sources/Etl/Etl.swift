//Solution goes in Sources
class ETL {
    static func transform(_ input: [ Int: [String] ]) -> [String: Int] {
        var res: [String: Int] = [:]
        for (key, val) in input {
            for letter in val {
                res[letter.lowercased()] = key
            }
        }
        return res
    }
}
