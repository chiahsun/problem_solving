/**
 * @param {number[]} A
 * @return {number}
 */
var numberOfArithmeticSlices = function(A) {
    var cnt = [0, 0, 0, 1];
    function getCount(x) {
      if (x >= cnt.length) {
          for (var i = cnt.length; i <= x; ++i)
              cnt.push(i - 2 + cnt[i-1]);
      }

      return cnt[x];
    }

    var ans = 0;
    var nseq = 1, d = A[1] - A[0];
    for (var i = 2; i < A.length; ++i) {
      var dnow = A[i] - A[i-1];
      if (dnow == d) { ++nseq; }
      else {
        if (nseq >= 2) { ans += getCount(nseq+1); }
        nseq = 1; d = dnow;
      }
    }
    if (nseq >= 2) { ans += getCount(nseq+1); }
    return ans;
};
