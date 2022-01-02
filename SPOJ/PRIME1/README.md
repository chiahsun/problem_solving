# solve1.swift

We cannot use sieve method since for 1 <= M <= N <= 1000000000, N may be too large. (See tle1.swift)

Since N-M<=100000, we can check if each number in this range has divisor.

|Time|Mem|
|:-:|:-:|
|3.42|8.4M|
