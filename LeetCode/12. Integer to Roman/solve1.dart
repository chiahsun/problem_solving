class Solution {
  String intToRoman(int num) {
    List<String> res = [];
    List<List<String>> m = [
        ['M', 'CM', 'D', 'C', 'CD'], // 1000 900 500 100 400
        ['C', 'XC', 'L', 'X', 'XL'], //  100  90  50  10  40
        ['X', 'IX', 'V', 'I', 'IV'], //   10  9    5   1   4
    ];
    for (int i = 0, mul=100; i < 3; ++i, mul ~/= 10) {
        if (num >= mul*10) {
            int v = num ~/ (mul*10);
            num -= v * mul * 10;
            res = res + List.filled(v, m[i][0]);
        }
        if (num >= 9 * mul) {
            res.add(m[i][1]);
            num -= 9 * mul;
        }
        if (num >= 5 * mul) {
            res.add(m[i][2]);
            num -= 5 * mul;
            int v = num ~/ mul;
            num -= v * mul;
            res = res + List.filled(v, m[i][3]);
        }
        // print('num: $num mul: $mul');
        if (num >= 4 * mul) {
            res.add(m[i][4]);
            num -= 4 * mul;
        }
    }
    if (num > 0) {
        res = res + List.filled(num, 'I');
    }
    return res.join();
  }
}
