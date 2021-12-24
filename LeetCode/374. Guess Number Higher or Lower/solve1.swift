/** 
 * Forward declaration of guess API.
 * @param  num -> your guess number
 * @return 	     -1 if the picked number is lower than your guess number
 *			      1 if the picked number is higher than your guess number
 *               otherwise return 0
 * func guess(_ num: Int) -> Int 
 */

class Solution : GuessGame {
    func guessNumber(_ n: Int) -> Int {
        var lo = 1
        var hi = n
        while lo < hi {
            var mid = (lo+hi)/2
            var res = guess(mid)
            if res == 0 { lo = mid; break }
            if res > 0 { lo = mid+1 }
            else       { hi = mid }
        }
        return lo
    }
}