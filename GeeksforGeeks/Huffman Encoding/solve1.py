#User function Template for python3

import queue

class TreeNode:
    def __init__(self, freq, c):
        self.freq = freq
        self.c = c
        self.left = self.right = None

    def traversal(self, d, st, res):
        if self.c:
            cur = "".join(st)
            d[self.c] = cur
            res.append(cur)

        if self.left:
            st.append('0')
            self.left.traversal(d, st, res)
            st.pop()
        if self.right:
            st.append('1')
            self.right.traversal(d, st, res)
            st.pop()

    def __lt__(self, other):
        return self.freq < other.freq

class Solution:
    def huffmanCodes(self,S,f,N):
        # https://stackoverflow.com/questions/9289614/how-to-put-items-into-priority-queues
        pq, new_node = queue.PriorityQueue(), None
        ordered = sorted(list(range(N)), key=lambda i: f[i])
        f = list(map(lambda i: f[ordered[i]], ordered))
        S = list(map(lambda i: S[ordered[i]], ordered))

        for i in range(N):
            new_node = TreeNode(f[i], S[i])
            pq.put(new_node)
        while pq.qsize() > 1:
            fst = pq.get()
            snd = pq.get()
            new_freq = fst.freq + snd.freq
            new_node = TreeNode(new_freq, '')
            new_node.left = fst
            new_node.right = snd
            pq.put(new_node)
        d, res = {}, []
        new_node.traversal(d, [], res)
        # print(list(map(lambda c: d[c], S)))
        # print(res)
        return res

#{
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__':
    t=int(input())
    for i in range(t):
        S= input()
        N= len(S);
        f= [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.huffmanCodes(S,f,N)
        for i in ans:
            print(i, end = " ")
        print()
# } Driver Code Ends