def test_digit_cancelling_fractions():
    numerator = 1;
    dominator = 1;
    for a in range(1, 10):
        for b in range(1, 10):
            for c in range(a+1, 10): # a < c
                if a * (10 * b + c) == c * (10 * a + b):
                    print(a, b, '/', b, c);
                    numerator *= (10 * a + b);
                    dominator *= (10 * b + c);
    print(dominator//gcd(numerator, dominator));

def gcd(x, y):
    if x < y:
        return gcd(y, x);
    while y > 0:
        x, y = y, x % y;
    return x;

def test_gcd():
    print(gcd(10, 2) == 2);
    print(gcd(30, 17) == 1);
    print(gcd(2, 10) == 2);
    print(gcd(17, 30) == 1);

test_gcd();
test_digit_cancelling_fractions();
