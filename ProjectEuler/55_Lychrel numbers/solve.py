def is_palindromic(number):
    number = str(number);
    for i in range(0, len(number)//2):
        if number[i] != number[len(number)-1-i]:
            return False;
    return True;

assert(is_palindromic(1221));
assert(is_palindromic(121));

def is_Lychrel_number(number, iter_times=50):
    for i in range(0, iter_times):
        reverse_number = int(str(number)[::-1]);
#        print(number, ' ', reverse_number);
        number = number + reverse_number;
#        print(number);
        if is_palindromic(number):
            return False;
    return True;

def test_Lychrel_number():
    res = 0;
    for i in range(1, 10000):
        if is_Lychrel_number(i):
            res += 1;
            print(i);
    print("num : ", res);

# print(is_Lychrel_number(5, 5));
test_Lychrel_number();
