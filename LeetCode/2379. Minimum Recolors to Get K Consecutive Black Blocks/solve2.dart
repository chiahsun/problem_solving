class Solution {
  int minimumRecolors(String blocks, int k) {
    int nWhite = 0;
    for (int i = 0; i < k; ++i) if (blocks[i] == 'W') ++nWhite;
    int res = nWhite;
    for (int i = k; i < blocks.length && res > 0; ++i) {
        nWhite += (blocks[i] == 'W' ? 1 : 0);
        nWhite -= (blocks[i-k] == 'W' ? 1 : 0);
        res = min(res, nWhite);
    }
    return res;
  }
}
