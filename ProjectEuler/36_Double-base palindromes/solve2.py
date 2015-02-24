def get_reversed_number(number):
    return int(str(i)[::-1]);

def get_binary_repr(number):
    return bin(number)[2:];

def is_palindrome_in_binary(number):
    binary_repr = get_binary_repr(number);
    l = len(binary_repr);
    hl = l // 2;
    return binary_repr[0:hl] == binary_repr[l-hl:l][::-1];

def is_palindrome_in_decimal(number):
    decimal_repr = str(number);
    l = len(decimal_repr);
    hl = l // 2;
    return decimal_repr[0:hl] == decimal_repr[l-hl:l][::-1];

res = 0;
for i in range(1, 1000000):
    if is_palindrome_in_binary(i) and is_palindrome_in_decimal(i): # TODO
        res += i;
        print(i);
print('sum = ', res);
