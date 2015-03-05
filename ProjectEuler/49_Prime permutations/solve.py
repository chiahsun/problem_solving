def get_prime_list(end=10000):
    a = [True] * (end+1);
    prime_list = [2];
    for i in range(3, len(a), 2):
        if a[i]:
            prime_list.append(i);
            for k in range(i+i, len(a), i):
                a[k] = False;
    return prime_list;

# print(get_prime_list(100));
   
# print(len(get_prime_list()));

prime_list = get_prime_list();

def get_counts_of_digits(number):
    lst = [0] * 10;
    for d in str(number):
        lst[int(d)] += 1;
    return lst;

def is_permutation(number1, number2):
    return get_counts_of_digits(number1) == get_counts_of_digits(number2);

def test_is_permutation():
    assert(is_permutation(1234, 4321));
    assert(is_permutation(2234, 4322));
    assert(not is_permutation(2234, 4321));

test_is_permutation();

def test_prime_permutations():
    for i in range(0, len(prime_list)):
        for k in range(i+1, len(prime_list)):
            prime_fst = prime_list[i];
            prime_snd = prime_list[k];
         
            prime_trd = prime_snd + prime_snd - prime_fst;
            if prime_trd < 10000 and is_permutation(prime_fst, prime_snd) and is_permutation(prime_fst, prime_trd) and prime_trd in prime_list:
                print(prime_fst, prime_snd, prime_trd, sep='');

test_prime_permutations();
