# Synopsis

Good introductory problem to the prime problem.

There are step-by-step explanations in the problem statement.

NOTE:

1. sqrt(x) is much more expensive that x * x

2. Seive is better if one want to count from 1 to n 


# Performance


## solve1.cc (use sqrt)

Runtime: 816 ms

Your runtime beats 2.22% of cppsubmissions.


## solve2.cc (not use sqrt)

Runtime: 200 ms

Your runtime beats 56.12% of cppsubmissions.

## solve3.cc (use sieve)

Runtime: 60 ms

Your runtime beats 74.23% of cppsubmissions.

Faster, since outest loop is n and second outer loop is proportional to prime size.


## solve1.py

Runtime: 822 ms

Your runtime beats 72.48% of pythonsubmissions.

## solve1.swift

Runtime: 85 ms, faster than 78.57% of Swift online submissions for Count Primes.

Memory Usage: 18.4 MB, less than 62.86% of Swift online submissions for Count Primes.
