def get_prime_list(end=97):
    """ inclusive for end """
    a = [True] * (end+1);
    prime_list = [2];
    for i in range(3, len(a), 2):
        if a[i]:
            prime_list.append(i);
            for k in range(i+i, len(a), i):
                a[k] = False;
    return prime_list;

def test_get_prime_list():
    print(get_prime_list());
    print(get_prime_list(100));

test_get_prime_list();

# bound = 1000;
bound = 100;
prime_list = get_prime_list(bound);

def is_prime(number):
    global prime_list;
#    if not (number <= prime_list[-1] ** 2):
#        print(number, ' > ', prime_list[-1], '^2');
#    assert(number <= prime_list[-1] ** 2);
    if not (number <= prime_list[-1] ** 2):
        prime_list = get_prime_list(number);
    return number > 1 and (number in prime_list or all(map(lambda prime: number % prime != 0, prime_list)));

def test_is_prime():
    print(not is_prime(1));
    print(is_prime(2));
    print(is_prime(3));
    print(not is_prime(9));
    print(is_prime(97));
    print(is_prime(3797));

test_is_prime();

def is_truncatable_prime(number):
    for i in range(0, len(str(number))):
        if not is_prime(int(str(number)[i:len(str(number))])):
            return False;
    for i in range(1, len(str(number))):
        if not is_prime(int(str(number)[0:i])):
            return False;
    return True;

def test_truncatable_prime_list1():
    bound = 1000000;
    print('prime_list_length: ', len(get_prime_list(bound)));
    truncatable_prime_list = list(filter(is_truncatable_prime, get_prime_list(bound)));
    truncatable_prime_list = list(filter(lambda x: not x in [2, 3, 5, 7], truncatable_prime_list));
    print(truncatable_prime_list);
    print(len(truncatable_prime_list));
    print(sum(truncatable_prime_list));

test_truncatable_prime_list1();
#    for 
