# Runtime

[solve1.cc]
31  Chiahsun Cheng (chiahsun cheng)   Accepted  C++11   0.006

[1] 0.000
[2] 0.003
[6] 0.006
[31] 0.009

# Tag

* dynamic programming
    * longest common subsequence


# Longest Common Subsequence Problem

For sequence A of length nA
    sequence B of length nB

the recursive function can be defined as

```
let lcs[cur_pos_of_A][cur_pos_of_B] denoted the size of longest subsequence available 
     if prefix A[0..cur_pos_of_A] is considered
               B[0..cur_pos_of_B]
```
   

```
At (cur pos of A, cur pos of B)

lcs[cur_pos_of_A + 1][cur_pos_of_B + 1] = lcs[cur_pos_of_A][cur_pos_of_B] + 1                                        # if sequenceA[cur_pos_of_A] == sequenceB[cur_pos_of_B]
                                      or  max(lcs[cur_pos_of_A+1][cur_pos_of_B], lcs[cur_pos_of_A][cur_pos_of_B+1])  # otherwise

```

## Example
```
         b    c    a
    a    0    0    0    0
         0    0    0    1  # update (1, 3) from (0, 2)

         b    c    a    d    a
    a    0    0    0    0    0    0
         0    0    0    1    1    1  # update (1, 5) from (0, 4)

         b
    a    0    0
    b    0    0
         0    1  # update (2, 1) from (1, 0)

         b    c
    a    0    0    0
    b    0    0    0
    c    0    1    1
         0    1    2  # update (3, 2) from (2, 1)

         b    c
    a    0    0    0
    b    0    0    0
    c    0    1    1
    c    0    1    2
         0    1    2  # update (4, 2) from (3, 1)

         b    c    a
    a    0    0    0    0
    b    0    0    0    1
    c    0    1    1    1
    c    0    1    2    2
    a    0    1    2    2
         0    1    2    3  # update (5, 3) from (4, 2)

         b    c    a    d    a
    a    0    0    0    0    0    0
    b    0    0    0    1    1    1
    c    0    1    1    1    1    1
    c    0    1    2    2    2    2
    a    0    1    2    2    2    2
         0    1    2    3    3    3  # update (5, 5) from (4, 4)

b c a
max length : 3 
```
