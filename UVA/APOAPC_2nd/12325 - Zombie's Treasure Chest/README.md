# Runtime

[solve1.cc]
16727664    32  Chiahsun Cheng (chiahsun cheng)   Accepted  C++11   0.000

[1] 0.000


# Explanation

We want to put more valuable things in, but constrained by its size.

### Example
1.     (N, S1, V1, S2, V2) = (10, 5, 5, 6, 8)    # not always valuable most
        (S1,S2) = (2, 0)   value  = 2 * 5 = 10
 not            = (0, 1)   value  = 1 * 8 = 8

2.     (N, S1, V1, S2, V2) = (53, 13, 13, 7, 7)  # Hard to find the combination to fit
        (S1,S2) = (3, 2) space = 13 * 3 + 7 * 2 = 53, value = 53        

## Pack which first
Let S1, V1, S2, V2 be the ordering.
[1] V2/S2 > V1/S1 (2 to be more valuable), or
[2] If V2/S2 == V1/S1, then let S2 be larger one. (pack large things first, then when we drop, we drop less, exchange more)

### Example 
     (S1, V1, S2, V2) = (1, 1, 2, 3)  [1]
     (S1, V1, S2, V2) = (1, 1, 2, 2)  [2]

1.  (N, S1, V1, S2, V2) = (7, 2, 2, 3, 4) 
    we have (S1,S2) = (0,2) first
2.  (N, S1, V1, S2, V2) = (53, 7, 7, 13, 13) 
    we have (S1,S2) = (0,4) first


## Stop criteria

1. Consider we have 2 to be more valuable, then the only way that to have 1 replace 2 to have more value is that when we use 2, we waste some space. But when we replace one 2 for some 1. The cost is (per-value-2 - per-value-1) * size-exchanged. When the cost be larger the max we can regain (waste space * per-value-1), we can stop.

2. When we have the exchange size that can be divided by S2, that means we already reach an end. It is free for these size to be changed by (more valuable) 2 to have (more valuable or) equal value. The exchange continues just as we have the exchange size replaced by S2 and go again the iteration.
   
