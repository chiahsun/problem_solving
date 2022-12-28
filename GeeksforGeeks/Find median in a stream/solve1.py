# {
# Driver Code Starts
# Initial Template for Python 3

import atexit
import io
import sys
import heapq
from collections import defaultdict
import math

# } Driver Code Ends
# User function Template for python3

''' 
use globals min_heap and max_heap, as per declared in driver code
use heapify modules , already imported by driver code
'''

import queue


class PQ:
    def __init__(self):
        self.pq = queue.PriorityQueue()

    def peek(self):
        return self.pq.queue[0][1]

    def get(self):
        return self.pq.get()

    def put(self, x):
        self.pq.put(x)

    def size(self):
        return self.pq.qsize()

    def empty(self):
        return self.pq.empty()


class Solution:
    def __init__(self):
        self.min_heap = PQ()
        self.max_heap = PQ()

    def balanceHeaps(self):
        if self.min_heap.size() < self.max_heap.size():
            _, v = self.max_heap.get()
            self.min_heap.put((v, v))

    # Balance the two heaps size , such that difference is not more than one.
    # code here

    '''
    You don't need to call getMedian it will be called itself by driver code
    for more info see drivers code below.
    '''

    def getMedian(self):
        if self.min_heap.size() > self.max_heap.size():
            return self.min_heap.peek()
        return (self.min_heap.peek() + self.max_heap.peek()) / 2

    # return the median of the data received till now.
    # code here

    def insertHeaps(self, x):
        if self.min_heap.size() > self.max_heap.size() and x >= self.min_heap.peek():
            _, v = self.min_heap.get()
            self.max_heap.put((-v, v))
            self.min_heap.put((x, x))
        elif not self.min_heap.empty() and x >= self.min_heap.peek():
            self.min_heap.put((x, x))
        else:
            self.max_heap.put((-x, x))

        self.balanceHeaps()


# {
# Driver Code Starts.

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        n = int(input())
        ob = Solution()
        for i in range(n):
            x = int(input())
            ob.insertHeaps(x)
            print(math.floor(ob.getMedian()))

# } Driver Code Ends