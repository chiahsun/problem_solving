class Solution {
  List<int> findSubstring(String s, List<String> words) {
    Map<String, int> dictWordPos = {};
    Map<int, int> dict = {};
    for (int i = 0; i < words.length; ++i) {
        final word = words[i];
        if (!dictWordPos.containsKey(word)) {
            dictWordPos[word] = i;
            dict[i] = 1;
        } else {
            dict.update(dictWordPos[word]!, (cnt) => ++cnt, ifAbsent: () => 1);
        }
    }

    final N = words.first.length;
    final matches = List<int>.filled(s.length, -1);
    for (int i = 0; i < s.length - N + 1; ++i) {
        for (final word in dictWordPos.keys) {
            if (s.substring(i, i+N) == word) {
                matches[i] = dictWordPos[word]!;
                break;
            }
        }
    }

    var defaultC = List<int>.filled(words.length, 0);
    dict.forEach((wordPos, cnt) => defaultC[wordPos] = cnt);
    List<int> res = [];
    for (int i = 0; i < N; ++i) {
        var C = List.from(defaultC), cntC = words.length;
        int? start = null;
        for (int k = i; k < matches.length; k += N) {
            if (matches[k] == -1) {
                C = List.from(defaultC);
                cntC = words.length;
                start = null;
            } else {
                if (start == null) {
                    start = k;
                }
                if (C[matches[k]] > 0) {
                    C[matches[k]] -= 1;
                    --cntC;
                } else {
                    int m = start!;
                    for (; matches[m] != matches[k]; m += N) {
                        ++cntC;
                        C[matches[m]] += 1;
                    }
                    start = m + N;
                }
                if (cntC == 0) res.add(start);
            }
        }
    }

    return res;
  }
}


