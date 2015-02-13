def get_mult(last = 10):
    mod = 10000000000;
    res = 0;
    for i in range(1, last+1):
        tmp = i;
        for k in range(i-1):
             tmp = (tmp * i) % mod;
        res = (res + tmp) % mod;

    return res;

print(get_mult(2));
print(get_mult(3));
print(get_mult(10));
print(get_mult(1000));

