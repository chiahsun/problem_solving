import math;
def get_prime_list(end = math.floor(math.sqrt(28123))+1):
    a = [True] * (end + 1);
    prime_list = [2];
    for i in range(3, len(a), 2):
        if a[i]:
            prime_list.append(i);
            for k in range(i+i, len(a), i):
                a[k] = False;
    return prime_list;

prime_list = get_prime_list();
# print(prime_list);

def get_prime_factorization(number):
    factor_list = [];
    for prime in prime_list:
        cnt = 0;
        while number % prime == 0:
            number = number / prime;
            cnt += 1;
        if cnt > 0:
            factor_list.append((prime, cnt));
        if number == 1:
            break;
    if number > 1:
        factor_list.append((number, 1));
    return factor_list;

def test_prime_factorization():
    for i in range(1, 101):
        print(get_prime_factorization(i));

def get_sum_power_series(number, power):
    return math.floor((number ** (power+1) - 1) // (number - 1));

def get_sum_of_factors(number):
    sum = 1;
    factor_list = get_prime_factorization(number);
    for (prime, power) in factor_list:
        sum *= get_sum_power_series(prime, power);
    return sum;

def test_sum_of_factors():
    for i in range(1, 1000):
        print(i, " with sum = ", get_sum_of_factors(i));
# test_sum_of_factors();

def get_abundant_number_list():
    abundant_number_list = [];
    for i in range(2, 28123+1):
        s = get_sum_of_factors(i);
        if s > 2 * i:
            abundant_number_list.append(i);
    # print(abundant_number_list);
    # print(len(abundant_number_list));
    return abundant_number_list;

# test_abundant_number();

abundant_number_list = get_abundant_number_list();

max_val = 28123;
a = [False] * (max_val+1);
# print(a);
for x in abundant_number_list:
    for y in abundant_number_list:
        s = x + y;
        if s > max_val:
            break;
        a[s] = True;

res = 0;
for i in range(1, max_val+1):
    if not a[i]:
        res += i;
print(res);





