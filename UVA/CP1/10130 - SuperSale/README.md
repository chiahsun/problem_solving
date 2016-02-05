# Runtime

[solve1.cc]
1867    Chiahsun Cheng (chiahsun cheng)   Accepted  C++11   0.063

# Tag

* dynamic programming
    * 0-1 knapsack


# 0-1 KnapSack

Take 
    Object = { ($6, 1), ($10, 2), ($12, 3) }
    People = { 5 }
for example (from CLRS).

By greedy, we can only get { {$6, 1}, ($10, 2) } = $16

However, best is { ($10, 2), ($12, 3) } = $22

```
             0     1     2     3     4     5
0(dummy)     0     0     0     0     0     0
       1     0     0     0     0     0     0
       2     0     0     0     0     0     0
       3     0     0     0     0     0     0

             0     1     2     3     4     5
0(dummy)     0     0     0     0     0     0
       1     0     6     6     6     6     6
       2     0     0     0     0     0     0
       3     0     0     0     0     0     0

             0     1     2     3     4     5
0(dummy)     0     0     0     0     0     0
       1     0     6     6     6     6     6
       2     0     6    10    16    16    16
       3     0     0     0     0     0     0

             0     1     2     3     4     5
0(dummy)     0     0     0     0     0     0
       1     0     6     6     6     6     6
       2     0     6    10    16    16    16
       3     0     6    10    16    18    22

22
```

We add dummy object and initialize row[0] and col[0] to all zeros.

```
                        0     1     2     3     4     5   
 dummy object >  0(dummy)     0     0     0     0     0     0   < all zeros
                        1     0     0     0     0     0     0
                        2     0     0     0     0     0     0
                        3     0     0     0     0     0     0

                              ^
                          all zeros
```

Define the function

```
   best_val_before[n_object_considered][weight_allowed]
```

which means **if we considred object 1 ... object n (size: n_object_considred), under the allowed weight (weight_allowed), the best value we can get.**

then it can be defined recursively

```
   best_val_before[n_object_considered][weight_allowed]
 = max( best_val_before[n_object_considered-1][weight_allowed]
      , (object[n_object_considered].weight <= weight_allowed) ? object[n_object_considered].value + best_val_before[n_object_considered][weight_allowed-object[n_object_considered].weight]
                                                               : best_val_before[n_object_considered][weight_allowed]
```

which means

We either **take (if allowed weight is permitted)** or **not take** the _nth object_ while _the best value under each interested weight considerations for object 1 .. object n-1_ is computed before.


1. If allowed weight is larger than or equal to the nth object weight, 
    
    1. we can take it (then add the nth object value with best before (allowed weight - nth object weight))

    2. or dismiss it. (then best value is best before (allowed weight))

    3. We choose max of above two.

2. If allowed weight is less than nth object weight,

    1. We simply dismiss it. (then best value is best before (allowed weight))

### Example

```
best_val_before(2, 2) = max( best_val_before(1, 2)
                           , object[2].value + best_value_before[1][2-object[2].weight])   // object[2].weight : 2 <= allowed_wight : 2
                      = max( 6
                           , 10 + best_value_before[1](2-2))
                      = max(6, 10+0)
                      = 10
```

