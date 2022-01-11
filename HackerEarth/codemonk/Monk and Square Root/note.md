**Proposition**

Let $0 \leq N \lt M, N, M \in \mathbb{N}$

Show that $$N^2 \mod M \\ = (M - N)^2 \mod M$$

For example, $2^2 = 4 \mod 14$ and $12^2 = 4 \mod 14$

**Proof**

$\mod M$  is closed under addition and multiplication

$$
\begin{align}
 & (M - N)^2 \mod M \\
= & M^2 - 2MN + N^2 \mod M \\
= & ((M^2 \mod M) + ((-2MN) \mod M) + (N^2 \mod M) \mod M) \\
= & (0 + 0 + (N^2 \mod M) \mod M) \\
= & N^2 \mod M
\end{align}
$$