class Solution {
    func isPrefixOfWord(_ sentence: String, _ searchWord: String) -> Int {
        let words = sentence.split(separator: " ")
        let N = searchWord.count
        for i in 0..<words.count where words[i].count >= N {
            let word = words[i]
            var posWord = word.startIndex
            var posSearchWord = searchWord.startIndex
            var ok = true
            repeat {
                if word[posWord] != searchWord[posSearchWord] {
                    ok = false
                    break
                }
                posWord = word.index(after: posWord)
                posSearchWord = searchWord.index(after: posSearchWord)
            } while posSearchWord != searchWord.endIndex
            if ok {
                return i+1
            }
        }
        return -1
    }
}