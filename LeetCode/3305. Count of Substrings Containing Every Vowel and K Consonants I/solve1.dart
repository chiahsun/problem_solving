//     aeiou
//  a 011111
//  e 001111
//  i 000111
//  o 000011
//  u 000001
//  c 000000

//    ieaouqaaeiqi
// a 0001111233333
// e 0011111112222
// i 0111111111223
// o 0000111111111
// u 0000011111111
// c 0000001111122

class Solution {
  int countOfSubstrings(String word, int k) {
    final vowels = <String>['a', 'e', 'i', 'o', 'u'], N = word.length;
    int getPos(String c) {
        int pos = vowels.indexOf(c);
        return (pos != -1) ? pos : vowels.length;
    }
    List<List<int>> psum = List.generate(word.length+1, (_) => List.filled(vowels.length+1, 0, growable: false), growable: false);
    final M = psum.first.length;
    
    for (int i = 0; i < N; ++i) {
        int pos = getPos(word[i]);
        for (int j = 0; j < M; ++j) {
            psum[i+1][j] =  psum[i][j] + ((j == pos) ? 1 : 0);
        }
    }

    int res = 0;
    for (int i = 0; i < N-k+1; ++i) {
        for (int j = i+5+k; j <= N; ++j) {
            bool ok = (psum[j][M-1] - psum[i][M-1]) == k;
            for (int m = 0; ok && m < M-1; ++m) {
                if (psum[j][m] - psum[i][m] <= 0) ok = false;
            }
            if (ok) ++res;
        }
    }

    return res;
  }
}
