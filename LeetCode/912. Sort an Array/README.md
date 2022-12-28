# solve1.swift (Use library sorted)

Runtime: 324 ms, faster than 94.25% of Swift online submissions for Sort an Array.

Memory Usage: 18.3 MB, less than 60.92% of Swift online submissions for Sort an Array.

# solve2.swift (Use LSD radix sort)

A bit tricky for integer including negatives.

Runtime: 340 ms, faster than 77.01% of Swift online submissions for Sort an Array.

Memory Usage: 18.7 MB, less than 52.87% of Swift online submissions for Sort an Array.

# solve3.swift (Use MSD radix sort)

Runtime: 332 ms, faster than 80.46% of Swift online submissions for Sort an Array.

Memory Usage: 18.3 MB, less than 55.17% of Swift online submissions for Sort an Array.

# Reference

[String sort](https://algs4.cs.princeton.edu/lectures/keynote/51StringSorts-2x2.pdf)

# solve1.py

Heap sort See: https://leetcode.com/explore/learn/card/sorting/694/comparison-based-sorts/4436/

Runtime 3003 ms Beats 57.96%

Memory 21.3 MB Beats 96.24%

# solve2.py

Idea similar to quick sort

Runtime 2998 ms Beats 56.81%

Memory 21.7 MB Beats 75.65%

# solve3.py

Care about duplciate keys for solve2 version. Note the change from <= to <.

Runtime 2096 ms Beats 69.38%

Memory 21.3 MB Beats 96.21%

# solve4.py

3-way quick sort.

Runtime 2062 ms Beats 70.34%

Memory 21.3 MB Beats 91.51%

# solve5.py

solve4 add insertion sort cutoff

Runtime 1937 ms Beats 75.9%

Memory 21.4 MB Beats 91.51%

Note that the runtime for quick sort differs each time each it's randomized.

# solve6.py

3-way quick sort.

Why mem high ...

Runtime 2239 ms Beats 61.78%

Memory 33.1 MB Beats 5.31%
