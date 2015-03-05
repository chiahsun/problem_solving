import math;

# 9 = 7 + 2 * 1^2
def get_prime_list(end=100):
    a = [True] * (end + 1);
    prime_list = [2];
    for i in range(3, len(a), 2):
        if a[i]:
            prime_list.append(i);
            for k in range(i+i, len(a), i):
                a[k] = False;
    return prime_list;


def test_get_prime_list():
    print(get_prime_list());

# test_get_prime_list();


def test_goldbech_other_conjecture(bound=1000):
    prime_list = get_prime_list(bound);
    a = [False] * bound;
    for prime in prime_list:
        for i in range(1, math.ceil(math.sqrt(bound/2)+1)):
            val = prime + 2 * (i ** 2);
            if val < len(a):
                a[val] = True;
    for i in range(3, len(a), 2):
        if not a[i] and not i in prime_list:
            print(i);

test_goldbech_other_conjecture(1000);
test_goldbech_other_conjecture(10000);
test_goldbech_other_conjecture(100000);
