import math;
prime_list = [2, 3, 5, 7];

def is_prime(number):
    if number < 2:
        return False;
    global prime_list;

    for i in range(prime_list[-1]+2, math.floor(math.sqrt(number))+2, 2):
        for k in prime_list:
            if i % k == 0:
                break;
        else:
            prime_list.append(i);
    
    for i in prime_list:
        if number == i:
            return True;
        elif number % i == 0:
            return False;
        elif i > math.floor(math.sqrt(number))+1:
            return True;
    return True;

def get_prime_list(end=101):
    is_prime(end**2+1);
    prime_list_less = [];
    for i in prime_list:
        if i > end:
            break;
        prime_list_less.append(i);
    return prime_list_less;

def test_prime_list():
    print(get_prime_list(100));
    print(len(get_prime_list(1000)));
    print(len(get_prime_list(10000)));

test_prime_list();

def test_is_prime():
    print(is_prime(41));
    print(is_prime(1601));

test_is_prime();

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


# Observation
# n = 0: b should be prime
# n = 1: 1 + a + b should be prime -> a is odd 
def test_quadratic_formula():
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

test_quadratic_formula();

print(len(prime_list));

