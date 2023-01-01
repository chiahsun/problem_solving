class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        begin_id, end_id = -1, -1
        for word_id, word in enumerate(wordList):
            if begin_id == -1 and word == beginWord:
                begin_id = word_id
            if end_id == -1 and word == endWord:
                end_id = word_id
        if end_id == -1:
            return 0
        if begin_id == -1:
            begin_id = len(wordList)
            wordList.append(beginWord)
    
        bucket, N = defaultdict(list), len(beginWord)
        for word_id, word in enumerate(wordList):
            for i in range(N):
                star_word = word[:i] + '*' + word[i+1:]
                bucket[star_word].append(word_id)

        bucket = {k: v for k, v in bucket.items() if len(v) > 1}
        bucket_list = []
        in_bucket = [[] for _ in range(len(wordList))]
        for word_ids in bucket.values():
            bucket_id = len(bucket_list)
            for word_id in word_ids:
                in_bucket[word_id].append(bucket_id)
            bucket_list.append(word_ids)

        q, visited, cnt = [begin_id], {begin_id}, 1
        while q:
            qn = []
            for a in q:
                for bucket_id in in_bucket[a]:
                    for b in bucket_list[bucket_id]:
                        if b != a and b not in visited:
                            if b == end_id:
                                return cnt+1
                            visited.add(b)
                            qn.append(b)
            cnt += 1
            q = qn
                            
        return 0
