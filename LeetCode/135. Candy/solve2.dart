class Solution {
  int candy(List<int> ratings) {
    final N = ratings.length;
    final candies = List<int>.filled(N, 1);
    if (N == 1) return 1;
    for (int i = 0; i < N-1;) {
        if (ratings[i+1] == ratings[i]) {
            while (i+1 < N && ratings[i+1] == ratings[i]) {
                candies[i+1] = 1;
                ++i;
            }
        } else if (ratings[i+1] < ratings[i]) {
            while (i+1 < N && ratings[i+1] < ratings[i]) ++i;
            for (int k = i-1; k >= 0 && ratings[k] > ratings[k+1]; --k) {
                candies[k] = max(candies[k], candies[k+1]+1);
            }
        } else {
            candies[i+1] = 1 + candies[i];
            ++i;
        }
    }
    return candies.reduce((a, b) => a + b);
  }
}
