# solve1.cc

Use sort and detect adjacent elements;

53 / 53 test cases passed.
Status: Accepted
Runtime: 15 ms

Your runtime beats 35.02 % of cpp submissions.

# solve2.cc

53 / 53 test cases passed.
Status: Accepted
Runtime: 20 ms

Your runtime beats 12.82 % of cpp submissions.


# solve1.py

As problem reqeusted, use O(1) space.

[Reference solution](http://bookshadow.com/weblog/2015/09/28/leetcode-find-duplicate-number/) Use cycle detection and find where ring begins. Truly ingenious.

53 / 53 test cases passed.
Status: Accepted
Runtime: 51 ms

Your runtime beats 44.99 % of python submissions.

```
1 -> 2 -> 3 -> 4 -> 5 -> 6
                \       /
                 8 <- 7

1 2 3 4 5 6 7 8 4 5 6 7 8
2 4 6 8 5 


        6 7 8 4 5 6 7 8 4
        1 2 3 4 5 6 7 8 4
```

For first run, we find the element we come across (i.e. 5) by 1-speed and 2-speed pointers.

For second run, we set one pointer to start(i.e. 0) and another pointer at cross point(i.e. 5) and both 1-speed.

Since we know that 1 2 3 4 5 and 6 7 8 4 5 has the same length and the same suffix from the first iteration, we can find where the cycle begins by just finding where they come across by the same speed.
