This is a variant of the Josephus problem since $1$ is striked out first. 

Let's define $tru(x, N)$ as $x - n \lfloor \frac{x-1}{n} \rfloor$, which can also be denoted as

$$
x \quad \mathrm{tru}(N)
$$

It is used to truncate mutiples of $N$ until x is less or equal to N(like mod but not mod).


Therefore, the answer should be $J'(N,k) = J(N-1, k)+1 \quad \mathrm{tru}(N)$

We know that 

$$
\begin{align}
& J(1, k) = 1 \\
& J(N, k) = J(N-1, k) + k & \mathrm{tru}(N)
\end{align}
$$

When $k = 5$,

$$
\begin{array}{c|lc}
N    & 1 & 2 & 3 & 4 & 5 & 6 & 7 & 8 & 9 & 10 & 11 & 12 & 13 & 14 & 15 & 16\\
\hline
J(N, 5) & 1 & 2 & 1 & 2 & 2 & 1 & 6 & 3 & 8 & 3 & 8 & 1 & 6 & 11 & 1 & 6 \\
\end{array}
$$

For example,

$
\begin{align}
J(2,2) & = J(1,2)+5 \quad \mathrm{tru}(2) \\
& = 1 + 5 \quad \mathrm{tru}(2) \\
& = 2
\end{align}
$

$
\begin{align}
J(3,2) & = J(2,2)+5 \quad \mathrm{tru}(3) \\
& = 2 + 5 \quad \mathrm{tru}(3) \\
& = 1
\end{align}
$

$
\begin{align}
J(4,2) & = J(3,2)+5 \quad \mathrm{tru}(4) \\
& = 1 + 5 \quad \mathrm{tru}(4) \\
& = 2
\end{align}
$

Therefore, 

$
\begin{align}
J'(17,5) & = J(16,5)+1 \quad \mathrm{tru}(17) \\
& = 6 + 1 \quad \mathrm{tru}(4) \\
& = 7
\end{align}
$

For the sample input, we want to find $k$ such that $J'(N,k) = 13$


$$
\begin{array}{c|lc}
N & 13 & 14 & 15 & 16\\
\hline
k \text{ in } J'(N, k)  & 1 & 2 & 1 \\
\end{array}
$$

$
\begin{align}
J'(17,k) & = J(17-1, k)+1 \quad \mathrm{tru}(17) \\
\end{align}
$

$J(16, k) = 12$

$$
\begin{array}{c|lc}
N    & 1 & 2 & 3 & 4 & 5 & 6 & 7 & 8 & 9 & 10 & 11 & 12 & 13 & 14 & 15 & 16 & 17\\
\hline
J(N, 2) & 1 & 1 & 3 & 1 & 3 & 5 & 7 & 1 & 3 & 5 & 7 & 9 & 11 & 13 & 15 & 1 & 3 \\
\end{array} \\
$$

$$
\begin{array}{c|lc}
N    & 1 & 2 & 3 & 4 & 5 & 6 & 7 & 8 & 9 & 10 & 11 & 12 & 13 & 14 & 15 & 16 & 17\\
\hline
J(N, 3) & 1 & 2 & 2 & 1 & 4 & 1 & 4 & 7 & 1 & 4 & 7 & 10 & 13 & 2 & 5 & 8 & 11 \\
\end{array} \\
$$

$$
\begin{array}{c|lc}
N    & 1 & 2 & 3 & 4 & 5 & 6 & 7 & 8 & 9 & 10 & 11 & 12 & 13 & 14 & 15 & 16 & 17\\
\hline
J(N, 4) & 1 & 1 & 2 & 2 & 1 & 5 & 2 & 6 & 1 & 5 & 9 & 1 & 5 & 9 & 13 & 1 & 5 \\
\end{array} \\
$$

$$
\begin{array}{c|lc}
N    & 1 & 2 & 3 & 4 & 5 & 6 & 7 & 8 & 9 & 10 & 11 & 12 & 13 & 14 & 15 & 16& 17\\
\hline
J(N, 5) & 1 & 2 & 1 & 2 & 2 & 1 & 6 & 3 & 8 & 3 & 8 & 1 & 6 & 11 & 1 & 6 & 11 \\
\end{array}
$$

$$
\begin{array}{c|lc}
N    & 1 & 2 & 3 & 4 & 5 & 6 & 7 & 8 & 9 & 10 & 11 & 12 & 13 & 14 & 15 & 16& 17\\
\hline
J(N, 7) & 1 & 2 & 3 & 2 & 4 & 5 & 5 & 4 & 2 & 9 & 5 & 12 & 6 & 13 & 5 & \textbf{12} & 2 \\
\end{array}
$$

We found that $J(16,7) = 12$, so $k = 7$.