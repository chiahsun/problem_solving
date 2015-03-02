def get_prime_list(end=1000):
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

def is_prime(number):
    if number < 2:
        return False;
    for prime in prime_list:
        if prime == number:
            return True;
        elif number % prime == 0:
            return False;
    return True;

def test_is_prime():
    assert(all(map(is_prime, [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97])));
    print(prime_list);

def test_consecutive_prime_sum():
    prime_list = get_prime_list(10 ** 6);

    print(prime_list);
    max_sum = 0;
    max_length = 0;
    print("Length of prime list: ", len(prime_list));
    for i in range(0, len(prime_list)):
#        print(i);
        for k in range(i+1, len(prime_list)+1):
            cur_sum = sum(prime_list[i:k]);
            if cur_sum > 10 ** 6:
                break;
            if is_prime(cur_sum) and k-i > max_length:
                max_sum = cur_sum;
                max_length = k - i;
                print(prime_list[i:k]);
    print(max_sum);

test_consecutive_prime_sum();

# test_consecutive_prime_sum();

