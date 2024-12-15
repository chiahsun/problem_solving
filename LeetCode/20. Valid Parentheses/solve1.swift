class Solution {
    func isValid(_ s: String) -> Bool {
        var st: [Character] = []
        for c in s {
            switch c {
                case "(", "{", "[":
                    st.append(c)
                case ")", "}", "]":
                    guard !st.isEmpty else { return false }
                    let old = st.removeLast()
                    if (old == "(" && c != ")" 
                     || old == "{" && c != "}"
                     || old == "[" && c != "]") {
                        return false
                    }
                default:
                    break
            }
        }
        return st.isEmpty
    }
}