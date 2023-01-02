#User function Template for python3

class Solution:
    #Function to sort a list using quick sort algorithm.
    def quickSort(self,arr,low,high):
        if low >= high: return
        # arr[:lt] < pivot, arr[lt:gt] = pivot, arr[gt:] > pivot
        lt, gt, pivot, i = low, high+1, arr[low], low
        while i < gt:
            if arr[i] < pivot:
                if i != lt: arr[i], arr[lt] = arr[lt], arr[i]
                lt += 1
                i += 1
            elif arr[i] == pivot:
                i += 1
            else:
                gt -= 1
                arr[i], arr[gt] = arr[gt], arr[i]
        self.quickSort(arr, low, lt-1)
        self.quickSort(arr, i, high)
    
    def partition(self,arr,low,high):
        pass
    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t=int(input())
    for i in range(t):
        n=int(input())
        arr=list(map(int,input().split()))
        Solution().quickSort(arr,0,n-1)
        for i in range(n):
            print(arr[i],end=" ")
        print()

# } Driver Code Ends
