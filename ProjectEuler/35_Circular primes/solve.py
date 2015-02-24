import math;
def get_prime_list(max=1000000):
    bound = math.floor(math.sqrt(max))+2;
    a = [True] * bound;
    prime_list = [2];
    for i in range(3, len(a), 2):
        if a[i]:
            prime_list.append(i);
            for k in range(i+i, len(a), i):
                a[k] = False;
    return prime_list;

prime_list = get_prime_list();
# print(prime_list);

def is_prime(number):
    return (number in prime_list) or all(map(lambda prime: number % prime != 0, prime_list));

print(is_prime(2));
print(is_prime(3));
print(is_prime(17));
print(is_prime(18));
print(is_prime(22339));

def get_circular_numbers(number):
    number = str(number);
    res = [];
    for i in range(len(number)):
        res.append(int(number));
        number = number[1:] + number[0];
    return res;

def test_circular_numbers():
    print(get_circular_numbers(2));
    print(get_circular_numbers(3));
    print(get_circular_numbers(13));
    print(get_circular_numbers(197));

test_circular_numbers();

circular_prime_list = [2];
res = 0;
for i in range(3, 1000000, 2):
    res += 1;
    if all(map(is_prime, get_circular_numbers(i))):
        circular_prime_list.append(i);
       # print(i);

print(len(circular_prime_list));
