// https://dart.dev/language/extension-methods
extension MutationOnString on String {
    // https://stackoverflow.com/questions/52083836/how-to-replace-only-one-character-in-a-string-in-dart
    String replaceCharAt(int i, String c) => this.substring(0, i) + c + this.substring(i+1);
}

class Solution {
  int ladderLength(String beginWord, String endWord, List<String> wordList) {
    Map<String, int> wordIdMap= {};
    wordIdMap[beginWord] = 0;
    List<String> words = [beginWord];
    int beginWordId = 0, endWordId = -1;
    for (final word in wordList) {
        if (word == beginWord) continue;
        final wordId = words.length;
        wordIdMap[word] = wordId; words.add(word);
        if (word == endWord) endWordId = wordId;
    }
    if (endWordId == -1) return 0;

    Map<String, List<int>> adjCandidates = {};
    for (int wordId = 0; wordId < words.length; ++wordId) {
        final word = words[wordId];
        for (int i = 0; i < word.length; ++i) {
            final candidate = word.replaceCharAt(i, '-');
            if (!adjCandidates.containsKey(candidate)) adjCandidates[candidate] = [];
            adjCandidates[candidate]!.add(wordId);
        }
    }
    List<List<int>> E = List.generate(words.length, (i) => [], growable: false);
    // print('candidates: $adjCandidates');
    adjCandidates.forEach((word, candidates) {
        for (int i = 0; i < candidates.length; ++i) {
            for (int k =i+1; k < candidates.length; ++k) {
                E[candidates[i]].add(candidates[k]);
                E[candidates[k]].add(candidates[i]);
            }
        }
    });
    List<int> q = [beginWordId], qNext = [];
    final visited = List<bool>.filled(words.length, false);
    visited[beginWordId] = true;
    int steps = 1;
    // print(E);
    while (!q.isEmpty) {
        for (final wordId in q) {
            if (wordId == endWordId) return steps;
            for (final nextWordId in E[wordId]) {
                if (!visited[nextWordId]) {
                    visited[nextWordId] = true;
                    qNext.add(nextWordId);
                }
            }
        }
        ++steps; q = qNext; qNext = [];
    }
    return 0;
  }
}
