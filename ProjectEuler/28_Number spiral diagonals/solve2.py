# Closed form
# f(1)     = 1
# f(3)     = 4 * 1^2 + 10 * 1 + 10 + f(1)
# f(5)     = 4 * 3^2 + 10 * 3 + 10 + f(3)
# f(n+2)   = 4 * n^2 + 10 * n + 10 + f(n)

# f(n+2) = 4 * (1^2 + 3^2 + ... + n^2) + 10 * (1 + 3 + ... + n) + 10 * (n+1) / 2 + 1

# 1^2 = 1
# 1^2 + 3^2 = 10
# 1^2 + 3^2 + 5^2 = 35
def get_fst(n):
    n = (n+1)//2;
    return 4 * n * (n+1) * (2 * n + 1) // 6 - 4 * n * (n+1)//2 + n;

# 1
# 1 + 3 = 4
# 1 + 3 + 5 = 9 
def get_snd(n):
    n = (n+1)//2;
    return n * (n+1) - n;

def get_spiral(n):
    n = n - 2;
    return 4 * get_fst(n) + 10 * get_snd(n) + 10 * (n+1) // 2 + 1;

print("fst:");
print(get_fst(1));
print(get_fst(3));
print(get_fst(5));
print("snd:");
print(get_snd(1));
print(get_snd(3));
print(get_snd(5));
print("spiral:");
print(get_spiral(1));
print(get_spiral(3));
print(get_spiral(5));
print(get_spiral(1001));
