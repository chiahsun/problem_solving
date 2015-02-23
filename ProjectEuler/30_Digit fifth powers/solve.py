for i in range(0, 10):
    for k in range(0, 10):
        for m in range(0, 10):
            for n in range(0, 10):
                x = 1000 * i + 100 * k + 10 * m + n;
                y = i ** 4 + k ** 4 + m ** 4 + n ** 4;
                if x == y:
                    print(x);


