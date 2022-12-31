# Proof of the Math Approach

The idea is base on [A little explanation on GCD method. C++/Java/Python - Water and Jug Problem - LeetCode](https://leetcode.com/problems/water-and-jug-problem/solutions/83714/a-little-explanation-on-gcd-method-c-java-python/)

* Use the ideas in OP and comments

Consider two positive integers $x, y$ and an integer $t$.

We know that if $d = gcd(x, y)$, then there exists integers $a, b$ such that $ax + by = d$(just expand the formula during Euclidean GCD algorithm, or check extended Euclidean algorithm)

If $d \mid t$, then it follows that there exists integer $k$ such that $kd = t$; hence $k(ax + by) = t$.

The problem here is that if $t \leq max(x, y)$, can we use only two jugs without any other auxiliary jugs.

How do we represent the fact that use only two jugs without using any other auxiliary jugs?

Without loss of generality, let $x \gt y$.

Consider the state of either jug:

* F: Full 

* E: Empty

* P: Partially Full

Note that during the process $kd, kd \leq max(x, y)$ the following condition should not be violated:

1. Both empty

2. Both full

3. At least one of them is full or empty (or equivalently not both of them be partially full)

Actually, we prove by construction that $x \% d$, $2x \% d$, $(y-1)x \% d$ occurs in our process and they map to different values for $0, d, \cdots, (y-1)d$. Also notice that

$$
x + x \% y = (x + x) \% y = 2x \% y
$$

hence,

$$
(k-1)x + x\%y = kx \% y
$$

**Example**

Consider [5, 3] and target = 4.



| 5 | 3 | |
| :-: | :-: | :-: |
| 5 (F) | 0 (E) | $x$
| 2 (P) | 3 (F) | 
| 2 (P) | 0 (E) | $x \% y$
| 0 (E) | 2 (P) | 
| 5 (F) | 2 (P) | 
| 4 (P) | 3 (F) | 
| 4 (P) | 0 (E) | 
| 1 (P) | 3 (F) | 
| 1 (P) | 0 (E) | $(x + x \% y) \% y = 2x \% y$
| 0 (E) | 1 (P) | 
| 5 (E) | 1 (P) | 
| 3 (P) | 3 (F) |
| 3 (P) | 0 (E) | 
| 0 (E) | 0 (E) | $3x \% y$

$1, \cdots 5$ all appears since $gcd(5, 3) = 1$

where we see that $pq % y$ falls into $0, \cdots y-1$ and simply we put back values in $0, \cdots y-1$ to the larger jug and add multiple second jugs we have all variations.

**Example**

Consider [11, 4] and target = 1.

11      4

11 (F) 0 (E)

7 (P) 4 (F)

7 (P) 0 (E)

3 (P) 4 (F)

3 (P) 0 (E)

0 (E) 3 (P)

11 (F) 3 (P)

10 (P) 4 (F)

10 (P) 0 (E)

6 (P) 4 (F)

6 (P) 0 (E)

2 (P) 4 (F)

2 (P) 0 (E)

0 (E) 2 (P)

11 (P) 2 (P)

9 (P) 4 (F)

9 (P) 0 (E)

5 (P) 4 (F)

5 (P) 0 (E)

1 (P) 4 (F)

1 (P) 0 (E)

Consider [11, 4] and target = 8.

11 4

0 (E) 4 (F)

4 (P) 0 (E)

4 (P) 4 (F)

8 (P) 0 (E)


TODO: [11, 7]

**Example**

$[10, 6], t = {0, 2, 4, 6, 8, 10}$


$10 \% 6 = 4$

$20 \% 6 = 2$

$30 \% 6 = 0$

${0, 2, 4} + 0 = {0, 2, 4}$

${0, 2, 4} + 6 = {6, 8, 10}$

(TODO) Finish the idea first, complete the detailed proof later.

**Lemma**

Suppse two integers $x, y, x \gt y, gcd(x, y) = 1$, there exists integer $p$ such that

$\qquad px \% y$ falls into $0, \cdots y-1$

*Proof.*

TODO: Prove using the pigeonhole principle.

**Lemma**

Suppse two integers $x, y, x \gt y, gcd(x, y) = d$, there exists integer $p$ such that

$\qquad px \% y$ falls into $0, d, 2d \cdots qd$ where $qd$ is the largest possible integer less than $y$.

*Proof.*

TODO

**Corollary**

For $0 \lt d, 2d, \cdots, (k-1) d \lt max(x, y)$, $$d, 2d, \cdots, (k-1) d$$ 
can all be represented in the process.

*Proof.*

TODO

# Reference

[diehard.htm](https://www.math.tamu.edu/~dallen/hollywood/diehard/diehard.htm)

[Bézout's identity - Wikipedia](https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity)

