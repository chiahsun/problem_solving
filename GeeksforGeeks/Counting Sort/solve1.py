#User function Template for python3

class Solution:
    #Function to arrange all letters of a string in lexicographical 
    #order using Counting Sort.
    def countSort(self,arr):
        char_pos = lambda c: ord(c)-ord('a')
        
        R, A = 26, ["?"] * len(arr)
        cnt = [0] * (R+1)
        for a in arr:
            cnt[char_pos(a)+1] += 1
        for i in range(2, R):
            cnt[i] += cnt[i-1]
        for a in arr:
            A[cnt[char_pos(a)]] = a
            cnt[char_pos(a)] += 1
        return "".join(A)
            

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n = int(input())
        arr = str(input())
        ob = Solution()
        print(ob.countSort(arr))

# } Driver Code Ends
