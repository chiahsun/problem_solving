# solve1.swift

Runtime: 36 ms, faster than 100.00% of Swift online submissions for Single Number II.

Memory Usage: 14.8 MB, less than 33.33% of Swift online submissions for Single Number II.

# Ref sol explanation

See: https://leetcode.com/problems/single-number-ii/solutions/3714928/bit-manipulation-c-java-python-beginner-friendly

# solve1.dart (Counter for each bit)

Runtime 100 ms Beats 8.33%

Memory 158.56 MB Beats 8.33%

# solve2.dart (Don't use bitint conversion. Use 64 bits int directly)

Runtime 5 ms Beats 79.17%

Memory 147.38 MB Beats 100.00%


# solve3.dart

Use two integers, one means that that bit has been toggled once that anther means that bit has been toggled twice. We use integer to perform calculation on the whole word replacing using array for each bit position.

Runtime 1 ms Beats 95.83%

Memory 148.40 MB Beats 87.50%


