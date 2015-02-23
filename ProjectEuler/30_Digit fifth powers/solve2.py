print('6 * 9 ^ 5 = ', 6 * (9 ** 5));
print('7 * 9 ^ 5 = ', 7 * (9 ** 5));

sum = 0;
for p in range(0, 10):
    for q in range(0, 10):
        for i in range(0, 10):
            for k in range(0, 10):
                for m in range(0, 10):
                    for n in range(0, 10):
                        x = 100000 * p + 10000 * q + 1000 * i + 100 * k + 10 * m + n;
                        y = p ** 5 + q ** 5 + i ** 5 + k ** 5 + m ** 5 + n ** 5;
                        if x == y:
                            print(x);
                            sum += x;
print('sum = ', sum);
