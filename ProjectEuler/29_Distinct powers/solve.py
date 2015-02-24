import math;
def get_prime_list(max = 100):
    bound = math.floor(math.sqrt(max+1));
    prime_list = [2];
    seive = [False] * (max+1);
    for i in range(3, len(seive), 2):
        seive[i] = True;
    for i in range(3, len(seive), 2):
        if seive[i]:
            prime_list.append(i);
            for k in range(i+i, len(seive), i):
                seive[k] = False;
    return prime_list;

prime_list = get_prime_list();
# print(get_prime_list());

def get_prime_factorization(number):
    factor_list = [];
    for prime in prime_list:
        cnt = 0;
        while number % prime == 0:
            number = number // prime;
            cnt += 1;
        if cnt > 0:
            factor_list.append((prime, cnt));
        if number == 1:
            break;
    if number > 1:
        factor_list.append((number, 1));
    # return factor_list;
    return tuple(factor_list);

def test_prime_factorization():
    for i in range(1, 101):
        print(get_prime_factorization(i));

# test_prime_factorization();

# TODO: refactor to map version
def get_prime_factor_to_power(prime_factor, power):
    new_prime_factor = [];
    for (a, b) in prime_factor:
        new_prime_factor.append((a, b*power));
    return tuple(new_prime_factor); 

def test_prime_factor_to_power(end = 5):
    number_list = [];
    for a in range(2, end+1):
        for b in range(2, end+1):
            number_list.append(get_prime_factor_to_power(get_prime_factorization(a), b));

    print(len(number_list));
    print(len(set(number_list)));

test_prime_factor_to_power();
test_prime_factor_to_power(100);

# print(len(number_set));
