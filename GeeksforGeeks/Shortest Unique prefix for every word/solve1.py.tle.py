#User function Template for python3

class TrieNode:
    def __init__(self):
        self.A = [None] * 26
        self.cnt = 0
        self.isEnd = False
    
    @staticmethod
    def get_pos(c):
        return ord(c) - ord('a')

    def put(self, word):
        if not word:
            isEnd = True
            self.cnt = 1
            return 1
        c = word[0]   
        pos = TrieNode.get_pos(c)
        if self.A[pos] is None:
            self.A[pos] = TrieNode()
        cnt = self.A[pos].put(word[1:])
        self.cnt += cnt
        return self.cnt

class Trie:
    
    def __init__(self):
        self.root = TrieNode()


    def put(self, word):
        self.root.put(word)
        
        
    def find_prefix(self, word):
        p = self.root
        for i, c in enumerate(word):
            p = p.A[TrieNode.get_pos(c)]
            if p.cnt == 1:
                return word[:i+1]
        return ""
        

class Solution:
    def findPrefixes(self, arr, N):
        trie = Trie()
        for word in arr:
            trie.put(word)
        return [trie.find_prefix(wd) for wd in arr]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        arr=list(map(str,input().split()))
        
        ob = Solution()
        res = ob.findPrefixes(arr,N)
        for i in res:
            print(i,end=" ")
        print()
# } Driver Code Ends
