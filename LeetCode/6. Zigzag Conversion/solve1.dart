// 0   4    8
// 1 3 5 7  9
// 2   6   10

// 0    6      12  // 0  end=2k-2
// 1  5 7   11 13  // 1,end-1 2k-2
// 2 4  8 10       // 2,end-2
// 3    9          // 3

// 0      8       16
// 1   7  9     15
// 2  6  10   14
// 3 5   11 13
// 4     12

// 0 1 2 3 4

// 0 2
// 1 3
class Solution {
    String convert(String s, int numRows) {
        if (numRows == 1) return s;
        final List<String> res = [];
        final d = 2*numRows-2, N = s.length;
        for (int i = 0; i < N; i += d) res.add(s[i]);
        int a = 1, b = d-1;
        while (a < b) {
            int g = b-a;
            for (int i = a; ; i += d) {
                if (i < N) res.add(s[i]); else break;
                if (i+g < N) res.add(s[i+g]); else break;
            }
            ++a; --b;
        }
        for (int i = a; i < N; i += d) res.add(s[i]);
        return res.join();
    }
}
