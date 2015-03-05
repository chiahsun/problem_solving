import math; 
def get_prime_list(end=100):
    a = [True] * (end+1);
    prime_list = [2];
    for i in range(3, len(a), 2):
        if a[i]:
            prime_list.append(i);
            for k in range(i+i, len(a), i):
                a[k] = False;
    return prime_list;

# print(get_prime_list());

prime_list = get_prime_list();

def get_prime_factorization(number):
     global prime_list;

     sqrt_number = math.ceil(math.sqrt(number));
     if prime_list[-1] < sqrt_number:
         prime_list = get_prime_list(2 * sqrt_number);
     
     factor_list = [];
     for prime in prime_list:
         cnt = 0;
         while number % prime == 0:
             cnt += 1;
             number = number // prime;
         if cnt > 0:
             factor_list.append((prime, cnt));
     if number > 1:
         factor_list.append((number, 1));
     return factor_list;

def test_prime_facorization():
    print(get_prime_factorization(8));
    print(get_prime_factorization(13));
    print(get_prime_factorization(27));

# test_prime_facorization();

def test_consecutive_prime(end=1000, num=4):
    a = [False] * num;

    for i in range(1, end):
        for k in range(0, len(a)-1):
            a[k] = a[k+1];
        a[-1] = len(get_prime_factorization(i)) == num;
        if all(a):
            print(i-num+1);
            break;

test_consecutive_prime(1000, 2);
test_consecutive_prime(1000, 3);
test_consecutive_prime(1000000, 4);

