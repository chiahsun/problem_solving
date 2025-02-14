// 3 0 2  5  4                   8
// 3 0 2 10 40                 320
//                2      3 4         2
//            40/2=20   40 0        320/10=32
//
class ProductOfNumbers {
  List<int> L = [];
  ProductOfNumbers() { }

  void add(int num) {
    if (num == 0) L.clear();
    else          L.add(L.isEmpty ? num : L.last * num);
  }

  int getProduct(int k) {
    if (L.isEmpty) return 0;
    if (L.length == k) return L.last;
    if (L.length - k - 1 < 0) return 0;
    return L.last ~/ L[L.length - k - 1];
  }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = ProductOfNumbers();
 * obj.add(num);
 * int param2 = obj.getProduct(k);
 */
