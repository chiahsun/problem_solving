class Solution {
  int firstCompleteIndex(List<int> arr, List<List<int>> mat) {
    final M = mat.length, N = mat.first.length;
    final R = List<int>.filled(M, N), C = List<int>.filled(N, M);
    List<List<int>> P = List.generate(arr.length, (i) => [0, 0], growable: false);
    for (int i = 0; i < M; ++i)
        for (int k = 0; k < N; ++k)
            P[mat[i][k]-1] = [i, k];

    for (int i = 0; i < arr.length; ++i) {
        final pos = P[arr[i]-1];
        if ((--R[pos[0]]) == 0 || (--C[pos[1]]) == 0) return i;
    }

    return -1;
  }
}
