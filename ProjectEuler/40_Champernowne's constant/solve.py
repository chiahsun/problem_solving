# 1 ~ 9
# f(1) = 9
# 10 ~ 99
# f(2) = 99 - 10 + 1 = 90
# 100 ~ 999 
# f(3) = 999 - 100 + 1 = 900

# print(10**1 - 10 ** 0);
# print(10**2 - 10 ** 1);

debug = False;

def get_digit(x):
    ndigits_accumulated = 0;
    for i in range(1, 11):
        ndigits_per_number = i;
        ndigits_accumulated = ndigits_per_number * (10 ** ndigits_per_number - 10 ** (ndigits_per_number-1)) + ndigits_accumulated;
        if debug:
            print('digit accumulated : ', ndigits_accumulated);
        if x <= ndigits_accumulated:
            difference = (ndigits_accumulated - x) // ndigits_per_number;
            number = str((10 ** ndigits_per_number - 1) - difference); 
            if debug:
                print('number: ', number);
            pos = (ndigits_accumulated - x) % ndigits_per_number; 
            if debug:
                print('pos: ', pos);
            digit = number[len(number)-pos-1];
            return int(digit);

def test_get_digit():
    for i in range(1, 25):
        print(get_digit(i));

# test_get_digit();


def test_get_digit_from_10_of_power_1_to_10():
    res = 1;
    for i in range(0, 7):
        res *= get_digit(10 ** i);
    print(res);

test_get_digit_from_10_of_power_1_to_10();


