## Synopsis

Good introductory problem to the prime problem.

There are step-by-step explanations in the problem statement.

NOTE:

1. sqrt(x) is much more expensive that x * x

2. Seive is better if one want to count from 1 to n 


## Performance


#### solve1.cc (use sqrt)

20 / 20 test cases passed.
Status: Accepted
Runtime: 816 ms

Your runtime beats 2.22% of cppsubmissions.


#### solve2.cc (not use sqrt)

20 / 20 test cases passed.
Status: Accepted
Runtime: 200 ms

Your runtime beats 56.12% of cppsubmissions.


#### solve3.cc (use sieve)

20 / 20 test cases passed.
Status: Accepted
Runtime: 60 ms

Your runtime beats 74.23% of cppsubmissions.

Faster, since outest loop is n and second outer loop is proportional to prime size.


#### solve1.py

20 / 20 test cases passed.
Status: Accepted
Runtime: 822 ms

Your runtime beats 72.48% of pythonsubmissions.

