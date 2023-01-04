TODO: Refine proof. Messy now.

# Bound Meaning

Considef a point $P$ that if 

* all points in $[P: P+safeSize]$  are available (i.e. not forbiddened.),

then for any point $x, 0 \leq x \leq P$, $x$ is reachable and has the same shortest path as if we impose the bound as  $P + safeSize$ or not. 

* That is to say, the solution is the same either the bound exists or not. 

* That is to say, it's safe to stop the search if the value greater or equal to $P + safeSize$.

Next, we claim that a reasonable point of $P$ is $max(t, max(F))$.

1. If $P \lt max(F)$,  then there might be some forbidden points falling into $[P: P +safeSize]$, a contradiction to the requirement for $P$.

2. If $P \lt t$, then there exists point(s), $y \in Y, P \lt y \leq t$, such that $y$ is not guarantted be have the same solution if we impose the bound constraint, and $t \in Y$ in particular so it becomes meaningless. 

Therefore,  $P$ can be any point greater than $t$ and greater than any forbidden point and it's reasoable to have $P$ be the minimal of such points, that is $max(t, max(F))$.

## Discussion of Forward

Last, we need to determine $safeSize$. Before that, let's see for any points $x, P-a \leq x \leq P$, what would it value be for $x+a$.  It turns out that they will be $P, P+1, \cdots, P+(a-1), P+a$. Therefore, any point $x \leq P$ that performs increment a as one state change can only call into one of the value $P...P+a$.



Now consider any step backward, since we can only perform one step back in a row and suppose $b \gt a$, then

$P-a \leq x \leq P \leq x+a$ and $x + a - b$. Therefore, $[P, P+safeSize]$ is for $x$ to be able to reach $x+a-b, x+a-b+1, \cdots, x, x+1, \cdots, P-1, P$. 

For example, if $x+a \to \cdots \to x+a+1$ then $x+a+1-b$ is reachable.


## Discussion of Backward

Now supoose that $y$ and $[y, y+someSize]$ are all available and $a \lt b$, then 

y -> y - b trivial

y -> ... -> y-b+1 (by backward)

y -> ... -> y-b+2 (by backward)

...

y -> ... -> y-1 (by backward)

That is to say, if $[y, y+someSize]$ are all available, we can always find backward edge to (y-b)...(y-1).

## Combine Backward and Forward

Now consider $y$ as the position as $x+a$ in our discussion after applying forward edge, then if $[y, y+someSize]$ are all available, then (y-b)...(y-1) are reacheable by backward edge means if $[x+a, x+a+someSize]$ are all available, then (x+a-b)...(x+a-1) are reacheable by backward edge which implies it also holds for any position in $x, x-1, \cdots, x+a-1$, since taking $x$ for example, 

* $x$ succeed $[x, x+someSize]$ are all available by our discussion for $x \geq P$, so the it's reachabe via backward to $x-b, x-b+1, \cdots, x-1$.

Therefore, it means $y = x+a$ succeeed, then any point $y' \in [P, y]$ also succeed, since [y', y+someSize] are avaialbe implies by meaning of P and $[y, y+someSize]$ are all available.

Therefore, we see that y+someSize = P + safeSize which implies $P+safeSize = x+a+someSize$ where $x$ holds for the meaning of $P$, hence $safeSize = a + someSize$.

The left problem is that what is the value of someSize. (Spoilter: $b$)

## someSize

Let's start with the problem, given the same condition for $a, b$, if we start from $0$, what minimal range is needed for reachability and shortest path for $0, 0+1, \cdots, a-1$.

THen change to the orginal problem.

---

TODO: last proposition to prove



Last proposition to prove, we only need any points within $[0,a+b]$ for reachability and shortest path for $0, 0+1, \cdots, a-1$.





For any $v \lt P$, how many buffer, $size$, do we need to reserve such that if any value in $[P:P+size]$ is available, we have the same reachable states as if we do not put the size constraint. 

First, we pick $P = max(t, max(F))$, since we don't want any value in $$[P:P+size]$ is forbidden and since if we let $P* \lt t$, then any value in $[P*, t+1]$ is not guaranteed by our method and $t$, our target, is in them.

Suppose $a \lt b$ and we can only get backward one in a row.

TODO
For any value less than $P$ step onto points larger than $b$, suppose $a \lt b$, any value, $x$, must take one of $P, P+1, P+2, \cdots, P+b-2, P+b-1$ since $a \lt b$, if it can goes back without forbidden area, then it's ok. Otherwise, let $x' = x + a$, then $x' - b$ ...

TODO
, otherwise, if $x >= P + b$, then $x - b >= P$, it cannot step back to any value less than $P$, so it's meaningless.

# Simpler Problem

Let's begin with simpler problems. Given  $1 \leq a, b $, and source as $s$, target as $t$. No restriction on forward and backward count and no forbidden area. We consider reachability before counting the shortest path.

**Example 1**

$s = 0 \lt t = 5$, $a = 2 \lt b = 3$

| 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   |     |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| s   |     | 1   |     |     |     |     |     |     |     |     |
|     |     |     |     | 2   |     |     |     |     |     |     |
|     | 3   |     |     |     |     | 3   |     |     |     |     |
|     |     |     | 4   |     |     |     |     | 4   |     |     |
|     |     |     |     |     | 5   |     |     |     |     | 5   |

$s = 0 \lt t = 5$, $a = 2 \lt b = 4$

| 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   |     |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| s   |     | 1   |     | 2   |     | 3   |     | 4   |     | 5   |

$s = 0 \lt t = 4$, $a = 6 \lt b = 4$

| 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  | 12  |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| s   |     |     |     |     |     | 1   |     |     |     |     |     |     |
|     |     | 2   |     |     |     |     |     |     |     |     |     | 2   |
|     |     |     |     |     |     |     |     | 3   |     |     |     |     |
|     |     |     |     | 4   |     |     |     |     |     | 4   |     |     |

$s = 0 \lt t = 5$, $a = 6 \lt b = 4$

Same table above, but $t$ is unreachable.

1. If $s = 0, gcd(a, b) \nmid t$, then $t$ is not reachable.

Since for any $v = ma + nb$, $gcd(a, b) \mid v$. For example.

* $6 = 1 \cdot a + 0 \cdot b$
* $2 = 6 - 4 = 1 \cdot a + 0 \cdot b + (-1) \cdot b = 1 \cdot a + (-1) \cdot b$
* $12 = 2 \cdot a + 0 \cdot b + 0 \cdot b$
* $8 = 2 \cdot a + (-1) \cdot b$
* $4 = 2 \cdot a + (-2) \cdot b$
* $10 = 12 - 4 = 2 \cdot a + (-1) \cdot b$

Therefore, before any more condition imposed, if $gcd(a, b) \nmid t$, then $t$ is not reachable from $s = 0$.

Hence, for below reasoning, we simply remove position not divided by $gcd(a, b)$.

## Add backward once constraint

$s = 0 \lt t = 4$, $a = 6 \lt b = 4$

|     | 0   | 2   | 4   | 6   | 8   | 10  | 12  | 14  | 16  | 18  |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|     | s   |     |     |     |     |     |     |     |     |     |
| F   |     |     |     | 1   |     |     |     |     |     |     |
| B   |     |     |     |     |     |     |     |     |     |     |
| F   |     |     |     |     |     |     | 2   |     |     |     |
| B   |     | 2   |     |     |     |     |     |     |     |     |
| F   |     |     |     |     | 3   |     |     |     |     | 3   |
| B   |     |     |     |     | 3   |     |     |     |     |     |
| F   |     |     |     |     |     |     |     |     |     |     |
| B   |     |     | 4   |     |     |     |     | 4   |     |     |

If we add backward once constraint, we cannot reach $4$ by $0, 6, 12, 8, 4$ but there are alternative way to reach $8$ by forward as last step as $0, 6, 2, 8$ and thus $0, 6, 2, 8, 4$.

## Add forbidden areas

$s = 0 \lt t = 4$, $a = 6 \lt b = 4, F = [2]$

If we add $2$ to forbidden area, note that $4$ is not reachable now.

|     | 0   | 2   | 4   | 6   | 8   | 10  | 12  | 14  | 16  | 18  |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|     | s   | X   |     |     |     |     |     |     |     |     |
| F   |     |     |     | 1   |     |     |     |     |     |     |
| B   |     |     |     |     |     |     |     |     |     |     |
| F   |     |     |     |     |     |     | 2   |     |     |     |
| B   |     | X   |     |     |     |     |     |     |     |     |
| F   |     |     |     |     |     |     |     |     |     | 3   |
| B   |     |     |     |     | 3   |     |     |     |     |     |
| F   |     |     |     |     |     |     |     |     |     |     |
| B   |     |     |     |     |     |     |     | 4   |     |     |

The problem here is that how to terminate; that is, how do we know that we cannot reach 4 since all possiblity are block and explore further doesn't bring any more ways back.

$s = 4 \lt t = 0$, $a = 4 \lt b = 6, F = [2]$ but now we cannot forward twice in a row.

|     | 0   | 2   | 4   | 6   | 8   | 10  | 12  | 14  | 16  | 18  |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|     |     | X   | s   |     |     |     |     |     |     |     |
| F   |     |     |     |     | 1   |     |     |     |     |     |
| B   |     |     |     |     |     |     |     |     |     |     |
| F   |     |     |     |     |     |     |     |     |     |     |
| B   |     | X   |     |     |     |     |     |     |     |     |

It's seems all states explored from the target and we terminates but it is not always the case. In most other cases, we still have states waiting to explored.

We check another example.

$s = 0 \lt t = ?$, $a = 3 \lt b = 5$

|     | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  | 12  | 13  |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|     | s   |     |     |     |     |     |     |     |     |     |     |     |     |     |
| F   |     |     |     | 1   |     |     |     |     |     |     |     |     |     |     |
| B   |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| F   |     |     |     |     |     |     | 2   |     |     |     |     |     |     |     |
| B   |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| F   |     |     |     |     |     |     |     |     |     | 3   |     |     |     |     |
| B   |     | 3   |     |     |     |     |     |     |     |     |     |     |     |     |
| F   |     |     |     |     |     |     |     |     |     | 3   |     |     |     |     |
| B   |     |     |     |     |     | 4   |     |     |     |     |     |     |     |     |

$s = 0 \lt t = ?$, $a = 3 \lt b = 5$

0 --> 3 --> 6 --> 9 --> 12
  1 <-------
  1 --> 4 --> 7 --> 10 --> 13
    2 <-------
    2 --> 5 --> 8 -- > 11

$s = 0 \lt t = ?$, $a = 3 \lt b = 4$

0 --> 3 --> 6 --> 9 --> 12
    2 <-----
    2 --> 5 --> 8 --> 11 --> 14
  1 <-----
  1 --> 4 --> 7 -- > 10

If $gcd(a, b) = 1$, then even if there is backward once constraint, if there is no forbidden areas, we can reach all states.

$s = 0 \lt t = 1$, $a = 3 \lt b = 4, F=[5]$, now 1 is unreachable, how to prove it?

Start from 1 is easy since all states are blocked. 1 --> 5, but 5 is forbidden done. a <---- 1 but a < 1 so it's not possible.

Now consider $s = 0 \lt t = 7$, $a = 3 \lt b = 4, F = [4, 11]$

$s = 0 \lt t = 7, a = 3 \lt b = 4, F = [4,8]$

X: forbidden V: visited as forward, W: visited as backward
If a position is labeld W, then it still can be explored if visited forwad. If a position is labeled V, since it forward and backward was queued, we don't explore it further.
0 --> 3 --> 6 --> 9 --> 12
    2 <-----
    2 --> 5 --> X
  1 <-----
  1 --> X
          V <---- 9
                X <---- 12

0 
        X <-- 7 
              7 ----> 11
                X <-- 11

$s = 0 \lt t = 11$, $a = 3 \lt b = 5, F = [5,10]$

0 --> 3 --> 6 --> 9 --> 12 --> 15 --> 18 --> 21
  1 <-------
  1 --> 4 --> 7 --> X --> 13
    2 <-------
    2 --> X --> 8 -> 11
                                   16 <----- 21 can only backward one in a row

X --> 8
      8 <--  13
  X--------> 13
  X----------------> 16
             13 <-- 18

# Complete Run

Let the distance of complete run be $d_c$.

A complete run for all integers $0 \leq v \lt \operatorname{lcm}(a, b)$ within the distance of 

$a = 3, b = 5, lcm(a, b) = 15$

0 ---> 3 ---> 6 ---> 9 ---> 12
  1 <-------- 6
  1 ---> 4 ---> 7 ---> 10 ---> 13
    2 <-------- 7
    2 ---> 5 ---> 8 ---> 11

0: 0
1: 3
2: 6
3: 1, 9
4: 4, 12
5: 7

0 3 6 1 4 7 2 5 8 11

# Cases

We already know that $1 \leq a, b$.

$s = 0 \leq t \leq 2000$.

$1 \leq \text{forbidden}[i] \leq 2000$

$ \text{forbidden}[i] \in F$

## Case 1. $a \gt b$.

$a > b$, since we can only do b once in a row. If $a > b$, then $a-b \gt 0$.

If we have current value as v, then $v \lt v + a - b \lt v + a$. 

If the next value we pick $v' = v + a$, then its lower bound is $v + a - b$ since it never be the case that $v + a - b - b$ where uses two $b$ in a row and if we take a after each b by noticing that $a - b \gt 0$, $v + a - b + (a - b) \gt v + a - b.$.

If we consider $v$ only, then its lower bound is $v-b$.

When we search from $s$ to $t$, for any next value if $v' = v-b \gt t$, then we are done since $v-b$ is the lower bound.

## Case 2. $a \leq b$ and $a \mid b$ (Including $a = b$)

Note that $a = b$ falls into this category.

a = 2, b = 8

$a \mid b$, we simply ignore b for any $v' \gt v$ since do b is equivalent to not to do ka where ka = b and any ka would step so $b$ doesn't help to break through forbidden area.

The lower bound is still $v - b$.

If $t = 4$, then $2, 4$, we reach $4$ since we start from $0$, for any possible value that use $b$, $ka$ would be on it first.

## Case 3. $a \lt b$ and $a \not\mid b$

a = 2, b = 7

2, 4, 6, 8

8-7=1

(8+2)-7=3=(8-7)+2=1+2

(8+4)-7=5

(8+6)-7=7

(8+8)-7=9

If $0 \lt t \lt a$, then there is no solution.

Note that we cannot have other explict lower bound other than $0$ since $a - b \lt 0$ 

$v' = v + ma + nb = v + (m-n)a + n(a - b)  \lt v$ with $n \leq m$.

However since $a \lt b$ and $s = 0$, we can exploit some properties.

### Case 3.1 $a \lt t \lt b$.

If $a \leq t \leq b$, then $t = \{ka-b, (k+1)a-b, \cdots, (k+n)a - b\}$

where $(k+n)a-b \lt b \lt (k+n+1)a-b$

Note that since there are forbidden areas, (8+2)-7 is not equivalent to 8-7+2.

Consider $t = 3$, a possible trace is $0, 2, 4, 6, 8, 10, 3$

For $F = \{ 10 \}$,  $0, 2, 4, 6, 8, 1, 3$

For $F = \{ 1, 10 \}$,

Consider $t+b$ or $t-(p+1)a \lt 0 \lt t-pa \lt t-(p-1)a \lt \cdots \lt t-a \lt a$, if we cannot reach  one of $\{ t-pa, \cdots t-a, t+b\}$, then we cannot reach $t$.

From 0, if we cannot reach $t+b$ then we cannot reach $t + b + a$?  Since another way is reach $t+2b+a$. Yes we can.

$t + b = 3 + 7 = 10$

$t+b+a = 3+7+2=12$ 

0, 2, 4, 6, 8, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 12

3, 1, 8, 6, 13, 11, 18

0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 11, 13, 6, 8, 1, 3

### Case 3.2 $a \lt b \lt t$.
