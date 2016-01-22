import random;

print(1);

nelement = 1500;
print(nelement);

def get_rn():
    a = 2**28;
    return random.randint(-a, a);
    

for _ in range(nelement):
    print(get_rn(), get_rn(), get_rn(), get_rn());
