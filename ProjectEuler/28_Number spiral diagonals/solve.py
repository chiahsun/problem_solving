# Recursive method
#
# f(1) = 1
# f(3) = 25
# f(5) = 101
# f(n+2) = f(n) + 4 * n^2 + 10*n + 10

def get_spiral_count(end=1001):
    res = 1;
    n = 1;
    while n != end:
        res = res + 4 * (n ** 2) + 10 * n + 10;
        n += 2;
    return res;

print(get_spiral_count(1));
print(get_spiral_count(3));
print(get_spiral_count(5));
print(get_spiral_count(1001));
