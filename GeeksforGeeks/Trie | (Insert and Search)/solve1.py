#User function Template for python3

"""
class TrieNode: 
      
    def __init__(self): 
        self.children = [None]*26
  
        # isEndOfWord is True if node represent the end of the word 
        self.isEndOfWord = False
"""

def get_pos(c):
    return ord(c) - ord('a')

#Function to insert string into TRIE.
def insert(root,key):
    p = root
    for c in key:
        pos = get_pos(c)
        if p.children[pos] is None:
            p.children[pos] = TrieNode()
            
        p = p.children[pos]
    p.isEndOfWord = True
        

#Function to use TRIE data structure and search the given string.
def search(root, key):
    p = root
    for c in key:
        pos = get_pos(c)
        if p.children[pos] is None:
            return False
            
        p = p.children[pos]
    return p.isEndOfWord


#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
class TrieNode: 
      
    def __init__(self): 
        self.children = [None]*26
  
        # isEndOfWord is True if node represent the end of the word 
        self.isEndOfWord = False
  
class Trie: 
      
    # Trie data structure class 
    def __init__(self): 
        self.root =TrieNode()
        
#use only 'a' through 'z' and lower case
def charToIndex(ch):
    return ord(ch)-ord('a')

if __name__ == '__main__': 
    t=int(input())
    for tcs in range(t):
        n=int(input())
        arr=input().strip().split()
        strs=input()
        
        t=Trie()
        
        for s in arr:
            insert(t.root,s)
        
        if search(t.root,strs):
            print(1)
        else:
            print(0)
# } Driver Code Ends
