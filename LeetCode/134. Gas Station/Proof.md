First we can reduce two arrays into one array.

For example, gas = [1, 2, 3, 4, 5], cost = [3, 4, 5, 1, 2], then define

d[i] = gas[i] - cost[i], we have d = [-2, -2, -2, 3, 3].

Note that a solution exists if and only if $\sum_i d_i \geq 0$ and we will prove it later.

The problem then becomes, where to pick the start position, then

$$
\sum_{i=start}^{end} d_i \geq 0, \forall end \in \{ start+1, start+2, \cdots, start-1, start \} \mod N  \quad (*)
$$

where $N$ is the length of d.

For this example, if we pick start = 3.

sum(d[3:4]) = 3
sum(d[3:5]) = 3 + 3 = 6
sum(d[3:1]) = 3 + 3 + (-2) = 4
sum(d[3:2]) = 3 + 3 + (-2) + (-2) = 2
sum(d[3:3]) = 3 + 3 + (-2) + (-2) + (-2) = 0

All of them >=0, so start = 3 is valid.

It is easy to show that no solution exists if sum(d) < 0, since we pick any position as start, sum(d[start:start]) < 0 which definitly violate (*). 

Second, we show that if sum(d) >= 0, then a solution exists and the algorithm follows the concept.

```
a          b     c
--------------------------
|    -     |     +       |
--------------------------
           |  -  |   +   |
           ---------------
                 | - | + |
                 ---------
                     e   f
```

Suppose that sum(d) = 0. That is, sum(d[a:f]) = 0.

Suppose a prefix sum is negative, say sum(d[a:b]) < 0. Then sum(d[b:f]) > 0 and sum(d[a:b]) + sum(d[b:f]) = 0 since sum(d[a:f]) = 0.

We cannot easily pick b as the valid start since there may exist some negative number, say c, in [b:f] that d[b] sum up to such negative number may be negative.

However, consider it is the case, we have again sum(d[a:c]) < 0 since sum(d[a, b]) < 0 and sum(d[b, c]) < 0 but note that since total sum = 0, we have sum(d([a, c])) + sum(d[c,f]) = 0 where sum(d[c, f]) > 0 = - sum(d[a, c])

Again, we cannot simply pick c as start point, since there may have negative numbers in [c: f] and follow the same reasoning above. But the question becomes: will it go indefinitely?

Of course not, first, if all left numbers are negative, then they sum up is negative but the prefix sum is also negative, total sum is negative, a contradiction to total sum is zero.

And we notice that if all prefix sums are all negative, the all left numbers sum up to the absolute value of the sum of all prefix sums. There must exists some point, take e here for example, that

sum(d[a, b]) + sum(d[b,c]) + sum(d[c, e]) + sum(d[e, f]) = 0

Therefore, we pick e as start point, then 

d[e:f] > 0
d[e:f] + d[a,b] > 0
d[e:f] + d[a, b] + d[b,c] > 0
d[e:f] + d[a, b] + d[b,c] + d[c, e] = 0

Therefore, the algorithm is that is prefix sum is negative, we simply drop it, if current number is positive, we set it as the possible start and try to add to some point.

If the prefix sum is always positive, then the picked number is the answer; otherwise, there must be another number(by our proof above) and start from that number, it sum up to the end equals to the absolute value of prefix sum (which is negative) before such number and such number is next candidate. Since the process cannot go indefinitely, it must exists such number.

For sum(d) >0 case, it follows  the same reasoning as sum(d) = 0.

**Example**

[1, -4, 3, -2, -2, 1, 1, 1, 1]

1 Set as possible start

1-4 = -3 Thus, 1 cannot be start

Since previous prefix sum is negative, consider 3 as new possible start.

3+(-2) = 1. Keep 3 as possible start.

3+(-2)+(-2)=-1. 3 cannot be start.

Since previous prefix sum is negative, consider 1 as new possible start.

1+1 = 2 Keep 1 as start.

1+1+1 = 3 Keep 1 as start.

1+1+1+1 = 4 Keep 1 as start.

Notice that 1+(-4)+3+(-2)+(-2) = -4 and 1 + 1 + 1 + 1 = |-4| = 4. If there exists a valid prefix sum to the end, then it is valid since

1+1+1+1+1

1+1+1+1+1+(-4) >= 0

1+1+1+1+1+(-4)+3 >- 0

1+1+1+1+1+(-4)+3+(-2) >= 0

1+1+1+1+1+(-4)+3+(-2)+(-2) >= 0

"1 + 1 + 1 + 1 = 4 >= any of the part negative prefix sum" simply follows from the fact that  it is the absolute value of all the negative prefix sum.
