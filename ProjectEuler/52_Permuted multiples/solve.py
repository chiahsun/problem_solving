def count_digits(number):
    counts = [0] * 10;
    for i in str(number):
        counts[int(i)] += 1;
    return counts;

def is_same_digits(number1, number2):
    return count_digits(number1) == count_digits(number2);

def test_is_same_digits():
    print(is_same_digits(1234, 4231));
    print(is_same_digits(125874, 251748));

test_is_same_digits();

def test_permuted_multiples(mult = 2):
    for i in range(1, 300000):
        if is_same_digits(i, mult * i):
            print(i, ' ', mult * i);
            break;

def test_permuted_multiples_all():
    test_permuted_multiples();
    test_permuted_multiples(3);
    test_permuted_multiples(4);
    test_permuted_multiples(5);
    test_permuted_multiples(6);

def test_permuted_multiples_common():
    for i in range(1, 300000):
        if is_same_digits(i, 2 * i) and is_same_digits(i, 3 * i) and is_same_digits(i, 4 * i) and is_same_digits(i, 5 * i) and is_same_digits(i, 6 * i):
            print(i, ' ', 2 * i , ' ', 3 * i, ' ', 4 * i, ' ', 5 * i, ' ', 6 * i);
            break;

test_permuted_multiples_common();
