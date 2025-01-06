class Solution {

  List<String> fullJustify(List<String> words, int maxWidth) {
    final N = words.length;
    List<String> res = [];
    int totalLen = 0, wordsLen = 0, pos = 0;
    List<String> lineWords = [];

    List<int> addedLength(int curLen) => (totalLen == 0) ? [curLen, curLen] :[totalLen + curLen + 1, wordsLen + curLen];

    String process(bool end) {
        StringBuffer buffer = StringBuffer();
        if (lineWords.length == 1 || end) {
            for (int i = 0; i < lineWords.length; ++i) {
                if (i != 0) buffer.write(' ');
                buffer.write(lineWords[i]);
            }
        } else {
            final nSpace = (maxWidth - wordsLen) ~/ (lineWords.length-1);
            final spaces = ' ' * nSpace;
            int left = (maxWidth - wordsLen) % (lineWords.length-1);
            for (int i = 0; i < lineWords.length; ++i) {
                if (i > 0) buffer.write(spaces);
                if (i > 0 && left > 0) { buffer.write(' '); left--; }
                buffer.write(lineWords[i]);
            }
        }
        buffer.write(' ' * (maxWidth - buffer.length));
        return buffer.toString();
    }
    while (pos < N) {
        while (pos < N && addedLength(words[pos].length)[0] <= maxWidth) {
            [totalLen, wordsLen] = addedLength(words[pos].length);
            lineWords.add(words[pos++]);
        }
        res.add(process(pos == N));
        lineWords = []; totalLen = 0; wordsLen = 0;
    }
    return res;
  }
}
