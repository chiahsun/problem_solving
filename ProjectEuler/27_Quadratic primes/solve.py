import math;
def is_prime(number):
    if number == 2:
        return True;
    if number <= 0 or number == 1 or number % 2 == 0:
        return False;
    a = [True] * (math.floor(math.sqrt(number)) + 2);
    for i in range(3, len(a), 2):
        if a[i]:
            if number % i == 0:
                return False;
            for k in range(i+i, len(a), i):
                a[i] = False;
    return True;

def get_prime_list(end = 100):
    prime_list = [];
    for i in range(1, end+1):
        if is_prime(i):
            prime_list.append(i);
    return prime_list;

def test_prime_list():
    print(get_prime_list());
    print(len(get_prime_list(1000)));
    print(len(get_prime_list(10000)));

test_prime_list();

def get_prime_length_for_quadratic_formula(a, b):
    n = 0;
    cnt = 0;
    while is_prime((n ** 2) + a * n + b):
        cnt += 1;
        n += 1;
    return cnt;

def test_prime_length_for_quadratic_formula():
    print(get_prime_length_for_quadratic_formula(1, 41));
    print(get_prime_length_for_quadratic_formula(-79, 1601));

test_prime_length_for_quadratic_formula();

def test_quadratic_formula():
    max_len = 0;
    max_coef = (0, 0);
    for a in range(-999, 1000):
        for b in range(-999, 1000):
            length = get_prime_length_for_quadratic_formula(a, b);
            if length > max_len:
                max_len = length;
                max_coef = (a, b);
    print(max_coef);
    print(max_coef[0] * max_coef[1]);

# test_quadratic_formula();

# Observation
# n = 0: b should be prime
# n = 1: 1 + a + b should be prime -> a is odd 
def test_quadratic_formula2():
    max_len = 0;
    max_coef = (0, 0);

    prime_list_less_than_1000 = get_prime_list(1000);
    prime_list_less_than_1000 = prime_list_less_than_1000 + list(map(lambda x: -x, prime_list_less_than_1000));

    for a in range(-999, 1000, 2):
        for b in prime_list_less_than_1000:
            length = get_prime_length_for_quadratic_formula(a, b);
            if length > max_len:
                max_len = length;
                max_coef = (a, b);
    print(max_coef);
    print(max_coef[0] * max_coef[1]);

test_quadratic_formula2();
