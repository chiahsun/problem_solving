class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        bank, start_id, end_id = list(set(bank)), -1, -1
        for i in range(len(bank)):
            if start_id != -1 and end_id != -1:
                break
            if start_id == -1 and bank[i] == startGene:
                start_id = i
            if end_id == -1 and bank[i] == endGene:
                end_id = i
        if start_id == -1:
            start_id = len(bank)
            bank.append(startGene)

        bucket = defaultdict(list)
        for gene_id, gene in enumerate(bank):
            for i in range(len(gene)):
                generalized_one = gene[:i] + '*' + gene[i+1:]
                bucket[generalized_one].append(gene_id)
        # https://stackoverflow.com/questions/2844516/how-to-filter-a-dictionary-according-to-an-arbitrary-condition-function
        # bucket = dict(filter(lambda x: len(x[1]) > 1, bucket.items()))
        bucket = {k: v for k, v in bucket.items() if len(v) > 1}

        E = defaultdict(list)
        for bank_ids in bucket.values():
            N = len(bank_ids)
            for i in range(N):
                for k in range(N):
                    if k != i:
                        E[bank_ids[i]].append(bank_ids[k])

        q, s, cnt = [start_id], {start_id}, 0
        while q:
            qn = []
            for a in q:
                if a == end_id:
                    return cnt
                for b in E[a]:
                    if b not in s:
                        s.add(b)
                        qn.append(b)
            cnt += 1
            q = qn
        return -1

