# from functools import reduce;
# def factorial(number):
#    return reduce(lambda x, y: x*y, range(2, number+1), 1);

from math import factorial;


def get_nth_permutation(lst, nth=1):
    def get_factorial_sequence(length, nth):
        seq = [];
        for i in range(length-1, 0, -1):
            now = nth // factorial(i);
            seq.append(now);
            nth = nth - now * factorial(i);
        return seq;
    l = len(lst);
    factorial_seq = get_factorial_sequence(l, nth);
    res = [];
    for pos in factorial_seq:
        res.append(lst[pos]);
        lst = lst[:pos] + lst[pos+1:];
    return res + lst;

# def test_get_factorial_sequence():
#     x = 3;
#    for y in range(0, 7):
#        print('factorial_sequence(', x, ', ', y, ') = ', get_factorial_sequence(x, y));

# test_get_factorial_sequence();

for i in range(4):
    print(get_nth_permutation([0, 1, 2], i));

def get_prime_list(end = 10000):
    a = [True] * (end+1);
    prime_list = [2];
    for i in range(3, len(a), 2):
        if a[i]:
            prime_list.append(i);
            for k in range(i+i, len(a), i):
                a[k] = False;
    return prime_list;

def test_get_prime_list():
    print(get_prime_list(100));

test_get_prime_list();

prime_list = get_prime_list();

def is_prime(x):
    global prime_list;
    if x < 2:
        return False;
    for prime in prime_list:
        if x == prime:
            return True;
        if x % prime == 0:
            return False;
    return True;

def test_is_prime():
    assert(is_prime(2));
    assert(is_prime(7));
    assert(is_prime(97));
    assert(is_prime(39916801));

test_is_prime();

def test_get_nth_permutation():
    print('test nth permutation');
    print('get_nth_permutation(1)');
    for i in range(0, 10):
        print(get_nth_permutation(list(range(0, 5)), i));
    a = list(range(0, 5));
    # Note this implementation doesn't depend on compare function, so you should use get_nth_permutation(i) for i > 0, not recursively use it
    print('get_nth_permutation(2)');
    for i in range(0, 10):
        print(a);
        a = get_nth_permutation(a);
    print('get_nth_permutation(3)');
    for i in range(0, 10):
        print(get_nth_permutation(list(range(4, -1, -1)), i));

test_get_nth_permutation();

def test_pandigital_prime():
   # seq = [i for i in range(9, 0, -1)];
    seq = [i for i in range(7, 0, -1)];
    seq = list(map(str, seq));
#    print('seq = ', seq);
    for i in range(0, factorial(len(seq))):
        number = int(''.join(get_nth_permutation(seq, i)));
#        print(number);
        if is_prime(int(number)):
            print('is prime: ', number);
            break;
    else:
        raise;
    print('number = ', number);

test_pandigital_prime();
