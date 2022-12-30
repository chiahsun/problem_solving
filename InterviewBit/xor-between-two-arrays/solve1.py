class TrieNode:
    def __init__(self):
        self.next = [None] * 2

class Trie:
    def __init__(self):
        self.root = TrieNode()

    @staticmethod
    def to_bin_str(v, max_n_digits):
        v = bin(v)[2:]
        return "0" * (max_n_digits - len(v)) + v

    def put(self, v, max_n_digits):
        v = self.to_bin_str(v, max_n_digits)
        p = self.root
        for i in range(max_n_digits):
            cur = ord(v[i]) - ord('0')
            if not p.next[cur]:
                p.next[cur] = TrieNode()
            p = p.next[cur]

    def traversal(self, v, max_n_digits):
        v = self.to_bin_str(v, max_n_digits)
        p = self.root
        res = 0
        for i in range(max_n_digits):
            res <<= 1
            cur = ord(v[i]) - ord('0')
            if not p.next[1-cur]:
                p = p.next[cur]
            else:
                res += 1
                p = p.next[1-cur]
        return res


class Solution:
    @staticmethod
    def get_max_n_digits(A, B):
        res = 1
        for a in A:
            res = max(res, len(bin(a))-2)
        for b in B:
            res = max(res, len(bin(b))-2)
        return res

    # @param A : list of integers
    # @param B : list of integers
    # @return an integer
    def solve(self, A, B):
        trie = Trie()
        max_n_digits = self.get_max_n_digits(A, B)
        for a in A:
            trie.put(a, max_n_digits)
        res = A[0] ^ B[0]
        for b in B:
            res = max(res, trie.traversal(b, max_n_digits))
        return res


if __name__ == "__main__":
    s = Solution()
    A = list(map(int, input().strip().split()))[1:]
    B = list(map(int, input().strip().split()))[1:]
    print(s.solve(A, B))
