// 8,4,6,2,3
//         0  [] -> [3]
//       0    [3] -> [2]
//     -2     [2] -> [2,6]
//   -2       [2] -> [2,4]
// -4         [2,4] -> [2,4,8]


// 10,1,1,6
//        0   []  -> [6]
//      0     []  -> [1]
//    -1      [1] -> [1]
// 9          [1] -> [1, 10]
class Solution {
    func finalPrices(_ prices: [Int]) -> [Int] {
        var ans = prices
        var st: [Int] = []
        for i in stride(from: prices.count-1, through: 0, by: -1) {
            let cur = prices[i]
            while let top = st.last {
                if top <= cur { 
                    ans[i] -= top 
                    if top < cur { st.append(cur) }
                    break
                } else {
                    st.removeLast()
                }
            }
            if st.isEmpty { st.append(cur) }
        }
        return ans
    }
}