# Runtime

[solve1.cc]
Accepted    412K    47MS    C++ 708B

[1] 0MS

# Tag

* huffman coding

* priority queue

# Reference

[Text Compression with Huffman Coding @ youtube] (https://www.youtube.com/watch?v=ZdooBTdW5bM)


Suppose that each plank has the weight ai and each split is make two subsets
            {2, 6, 5, 3, 4}

        {6, 5}              {2, 3, 4}
      
      {6}     {5}          {4}     {2, 3}
                             
                                  {2}    {3} 

Total cost would be ||{2, 6, 5, 3, 4}|| + ||{6, 5}|| + ||{2, 3, 4}|| + ||{2, 3}||.

= 20 + 11 + 9 + 5 = 45

that equals to Sigma (ai * (di-1))
      
In this example, that is to say

6x2 + 5x2 + 4x2 + 2x3 + 3x3 = 45


To find such tree that minimize the cost, the tree is Huffman coding tree.
