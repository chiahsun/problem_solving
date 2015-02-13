def factorial(number):
    res = 1;
    for i in range(number, 1, -1):
        res *= i;
    return res;

# print(factorial(2));
# print(factorial(3));
# print(factorial(10));

def get_factorial_sequence(lst, nth):
    seq = [];
    for i in range(len(lst)-1, 0, -1):
        now = nth // factorial(i);
        seq.append(now);
        nth = nth - now * factorial(i);
    return seq;



for i in range(0, 6):
    print(get_factorial_sequence([0, 1, 2], i));
# print(get_factorial_sequence([0, 1, 2], 1));
# print(get_factorial_sequence([0, 1, 2], 2));
# print(get_factorial_sequence([0, 1, 2], 3));

def get_nth_permutation(lst, nth):
    l = len(lst);
    factorial_seq = get_factorial_sequence(lst, nth);
    res = [];
    for pos in factorial_seq:
        res.append(lst[pos]);
        lst = lst[:pos] + lst[pos+1:];
    return ''.join(map(str, res + lst));
print("Begin permute");

for i in range(0, 6):
    print(get_nth_permutation([0, 1, 2], i));

print(get_nth_permutation([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], 1000001));
print(get_nth_permutation([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], 1000000));
print(get_nth_permutation([0, 1, 2, 3, 4, 5, 6, 7, 8, 9],  999999));
# print(get_nth_permutation([0, 1, 2]), 0);
# print(get_nth_permutation([0, 1, 2]), 1);
# print(get_nth_permutation([0, 1, 2]), 2);
# print(get_nth_permutation([0, 1, 2]), 3);

# res = 2 * factorial(9)  +  6 * factorial(8) + 6 * factorial(7) + 2 * factorial(6) + 5 * factorial(5) + factorial(4) + 2 * factorial(3) + 2 * factorial(2);
# print(res);
