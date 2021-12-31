a = 600851475143
p = 2
while a > 1 and a % p == 0:
    a /= p

p = 3
while a > 1 and p*p <= a:
    while a % p == 0:
        a //= p
    p += 2

print(a)