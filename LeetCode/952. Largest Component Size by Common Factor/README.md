# Tag

`math` `dp`

# solve1.swift

Brute force O(N^2) with union find would lead to TLE.

Therefore, we use dynamic programming ideas here with a little math comprehension about divisor, prime here.

The algorithm would be O(M) where M is the total divisors for each number. However, we don't perform factorization but perform it implicitly. 

Runtime: 404 ms, faster than 100.00% of Swift online submissions for Largest Component Size by Common Factor.

Memory Usage: 16.2 MB, less than 75.68% of Swift online submissions for Largest Component Size by Common Factor.
