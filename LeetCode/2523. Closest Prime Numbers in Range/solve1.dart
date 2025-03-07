class Solution {
  List<int> closestPrimes(int left, int right) {
    final isPrime = List<bool>.filled(right+1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i*i <= right; ++i)
        if (isPrime[i])
            for (int k = i+i; k <= right; k += i)
                isPrime[k] = false;

    int num1 = -1, num2 = -1, d = right;
    for (int i = left, a = -1, b = -1; i <= right; ++i) {
        if (isPrime[i]) {
            if (b == -1) b = i;
            else {
                (a, b) = (b, i);
                if (b - a < d) {
                    num1 = a;
                    num2 = b;
                    d = b - a;
                }
                if (d == 2) break;
            }
        }
    }

    return [num1, num2];
  }
}
