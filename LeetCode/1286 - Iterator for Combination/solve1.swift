
class CombinationIterator {
    
    var characters: [Character]
    var targetLength: Int
    var A: [Int] = []
    
    init(_ characters: String, _ combinationLength: Int) {
        self.characters = Array(characters)
        for i in 0..<combinationLength {
            A.append(i)
        }
        targetLength = combinationLength
    }
    
    
    func next() -> String {
        if !hasNext() { return "" }
        
        let N = characters.count
        var s: [Character] = []
        for a in A {
            s.append(characters[a])
        }
        
        var ok = false
        for i in stride(from: targetLength-1, to: -1, by: -1) {
            if A[i] != N - (targetLength-i) {
                A[i] = A[i]+1
                
                for k in i+1..<targetLength {
                    A[k] = A[i]+(k-i)
                }
                
                ok = true
                break
            }
        }
        if !ok {
            A = []
        }
        return String(s)
    }
    
    func hasNext() -> Bool {
        return !A.isEmpty
    }
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * let obj = CombinationIterator(characters, combinationLength)
 * let ret_1: String = obj.next()
 * let ret_2: Bool = obj.hasNext()
 */