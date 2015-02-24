# 9! * 7 = 2540160
# 9! * 8 = 2903040

# so max 7 digits

factorial_list = [1, 1];
for i in range(2, 10):
    factorial_list.append(factorial_list[-1]*i);
# print(factorial_list);

def get_sum_digit_factorials(number):
    sum = 0;
    while number > 0:
        sum += factorial_list[number % 10];
        number = number // 10;
    return sum;

# print(get_sum_digit_factorials(145));

def test_digit_factorials():
    equal_list = [];
    for i in range(1, 9999999):
        if i == get_sum_digit_factorials(i) and i != 1 and i != 2:
            equal_list.append(i);
    print(sum(equal_list));
                                
test_digit_factorials(); 
