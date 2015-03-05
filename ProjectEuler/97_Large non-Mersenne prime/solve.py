# 28433×2^7830457+1

res = 28433;
for i in range(0, 7830457):
    res  = 2 * res % (10 ** 10);
res += 1;

print(res % (10 ** 10));

