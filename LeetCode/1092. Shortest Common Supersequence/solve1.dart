//    cab  cab
//   0000 ca
// a 0011   b
// b 0012    a
// a 0012    c
// c 0112

//    ab a c
//  c ab

//    acb   acb
//.  0000  a
// a 0111   cd
// d 0111    b
// b 0112

// a db
// ac b

// Two the same as cur, choose any of them
// Two less than cur, them choose diagnol

// https://web.ntnu.edu.tw/~algo/Subsequence2.html

class Solution {
  String shortestCommonSupersequence(String str1, String str2) {
    final M = str1.length, N = str2.length, res = <String>[];
    final dp = List<List<int>>.generate(M+1, (i) => List.filled(N+1, 0, growable: false), growable: false);

    for (int i = 0; i < M; ++i) {
        for (int k = 0; k < N; ++k) {
            if (str1[i] == str2[k]) dp[i+1][k+1] = dp[i][k]+1;
            else                    dp[i+1][k+1] = max(dp[i+1][k], dp[i][k+1]);
        }
    }

    for (int i = M, k = N; i > 0 || k > 0;) {
        if (i > 0 && dp[i-1][k] == dp[i][k]) {
            res.add(str1[--i]);
        } else if (k > 0 && dp[i][k-1] == dp[i][k]) {
            res.add(str2[--k]);
        } else {
            res.add(str1[--i]); --k;
        }
    }

    return res.reversed.join();
  }
}
