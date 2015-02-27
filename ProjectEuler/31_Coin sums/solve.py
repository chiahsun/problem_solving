# 1p, 2p, 5p, 10p, 20p, 50p, 100p, 200p

coin_list = [200, 100, 50, 20, 10, 5, 2, 1];

# f(1, 1) = 1
# f(2, 2) = 2
# f(5, 5) = 4
# f(10, 10) = 11

# Reference
# http://stackoverflow.com/questions/6667201/how-to-define-two-dimensional-array-in-python
NOT_COMPUTED = -1;
combination_list = [[NOT_COMPUTED for x in range(0, 201)] for x in range(0, 201)];

# f(10, 10)  # coin value 10 with max coin value 10

# f(1, 1) = 1
# f(2, 2) = 2
# f(4, 2) = 3
# f(6, 2) = 4
# f(8, 2) = 5
# f(10, 2) = 6
# f(5, 5) = 4
# f(10, 10) = 11

# f(1, 1) : 1p x 1
# f(2, 2) : 2p x 1
#           1p x 2
# f(5, 5) : 5p x 1
#           2p x 1 1p x 3
#           2p x 2 1p x 1
#           5p x1
# f(10, 10) : 10p x 1
#             5p x 1 1p x 5
#             5p x 1 2p x 1 1p x 3
#             5p x 1 2p x 2 1p x 1
#             5p x 2
#             2p x 1 1p x 8
#             2p x 2 1p x 6
#             2p x 3 1p x 4
#             2p x 4 1p x 2
#             2p x 5
#             10p x 1

# f(10, 10) = 1           # 1x10p coin and left coins with max value of 10p
#           + 1 x f(5, 5) # 1x5p  coin and left coins with max value of 5p
#           + 1 x f(8, 2) # 1x2p  coin and left coins with max value of 2p
#           + 1 x f(9, 1) # 1x1p  coin and left coins with max value of 1p
#
# where f(n, 1) with n > 0 can be simplified to 1 


def get_number_combination(value, max_coin_value):
    if value == 0:
        return 0;

    if max_coin_value == 1:
        return 1;

    if combination_list[value][max_coin_value] != NOT_COMPUTED:
        return combination_list[value][max_coin_value];

    res = 0;
    for coin in coin_list:
        if coin <= max_coin_value:
            if value > coin:
                res += get_number_combination(value - coin, coin);
            elif value == coin:
                res += 1;
    combination_list[value][max_coin_value] = res;
    return res;

def test_number_combination(value, max_coin_value):
    print("coin_combination(", value, ", ", max_coin_value, ") = ", get_number_combination(value, max_coin_value));

def test_all_number_combination():
    test_number_combination(1, 1);
    test_number_combination(2, 2);
    test_number_combination(4, 2);
    test_number_combination(6, 2);
    test_number_combination(8, 2);
    test_number_combination(10, 2);
    test_number_combination(5, 5);
    test_number_combination(10, 10);
    test_number_combination(200, 200);

# test_number_combination(6, 2);
test_all_number_combination();
