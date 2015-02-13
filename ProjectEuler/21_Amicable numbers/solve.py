
def get_prime_list(max = 100):
    res = [2];
    is_prime = [True] * max;
    for i in range(3, max, 2):
        if is_prime[i]:
            res.append(i);
            for k  in range(i+i, max, i):
                is_prime[k] = False;
    return res;

prime_list = get_prime_list();
# print(get_prime_list());

def get_geometry_sum(mul, num):
    return (mul ** num - 1) // (mul - 1);


def get_factorization(number):
    global prime_list;
    factors = {};
    for prime in prime_list:
        while number % prime == 0 and number > 1:
            number = number // prime;
            if prime in factors:
                factors[prime] += 1;
            else:
                factors[prime] = 1;
#        print(factors, " after ", number);
    else:
        if number > 1:
            factors[number] = 1;
    return factors;


def get_proper_sum(number):
    if number == 0:
        return 0;
    factorization_list = get_factorization(number);
    # print(factorization_list);
    proper_sum = 1;
    for prime, exp in factorization_list.items():
        proper_sum *= get_geometry_sum(prime, exp+1);
    
    proper_sum = proper_sum - number;
    return proper_sum;

# print(get_geometry_sum(2, 3));
# print(get_geometry_sum(5, 2));
# print(get_proper_sum(220));
# print(get_proper_sum(284));

# for i in range(0, 100):
#    print(get_proper_sum(i));
print(get_proper_sum(0));
print(get_proper_sum(1));

def get_proper_sum_list(max = 10000):
    lst = [];
    for i in range(0, max):
        lst.append(get_proper_sum(i));
    return lst;

print(get_proper_sum_list(300));

def get_result(max = 10000):
    proper_sum_list = get_proper_sum_list(max);
    d = dict();
    for i, x in enumerate(proper_sum_list):
        d[i] = x;
    amicable_number_sum = 0;
    for i, x in enumerate(proper_sum_list):
        if x < len(proper_sum_list) and d[x] == i and x != i:
            amicable_number_sum += x;
    return amicable_number_sum;

print(get_result());

