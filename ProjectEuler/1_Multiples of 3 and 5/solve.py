# f(10) = 23
# 3 5 6 9

# f(1000) = ?

def get_result1(max = 10):
    def sums(x):
        s = 0;
        for i in range(x, max, x):
            s += i;
        return s;
    return sums(3) + sums(5) - sums(15);

def get_result2(max = 10):
    def sums(start, end, step):
        n = (end - start) // step;
        return (start + start + n * step) * (n + 1) // 2;
    return sums(3, max-1, 3) + sums(5, max-1, 5) - sums(15, max-1, 15);

print(get_result1(10));
print(get_result1(1000));

print(get_result2(10));
print(get_result2(1000));
