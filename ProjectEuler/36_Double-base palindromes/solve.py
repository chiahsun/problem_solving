def get_reversed_number(number):
    return int(str(i)[::-1]);

def get_binary_repr(number):
    return bin(number)[2:];

def is_palindrome_in_binary(number):
    binary_repr = get_binary_repr(number);
    l = len(binary_repr);
    hl = l // 2;
    return binary_repr[0:hl] == binary_repr[l-hl:l][::-1];

for i in range(100, 999+1):
    number = 1000 * i + get_reversed_number(i);
    if is_palindrome_in_binary(number):
        print(number);

for i in range(10, 99+1):
    number = 100 * i + get_reversed_number(i);
    if is_palindrome_in_binary(number):
        print(number);

for i in range(1, 9+1):
    number = 10 * i + get_reversed_number(i);
    if is_palindrome_in_binary(number):
        print(number);

for i in range(1, 9+1):
    for mid in range(0, 9+1):
        number = 100 * i + 10 * mid + i;
        if is_palindrome_in_binary(number):
            print(number);


for i in range(10, 99+1):
    for mid in range(0, 9+1):
        number = 1000 * i + 100 * mid + get_reversed_number(i);
        if is_palindrome_in_binary(number):
            print(number);

for i in range(1, 9+1):
    number = i;
    if is_palindrome_in_binary(number):
        print(number);

print('sum = ', sum([585585
,    7447
 ,   9009
 ,   33
 , 99
 ,   313
 ,   585
 ,   717
 ,   15351
 ,   32223
 ,   39993
 ,   53235
 ,   53835
 ,   73737
 , 1, 3, 5, 7, 9]));
