def is_pandigital(x, y, z):
    counts = [0] * 10;
    for i in str(x) + str(y) + str(z):
        counts[int(i)] += 1;

    return counts[0] == 0 and all(map(lambda x : x == 1, counts[1:]));

def test_number_of_pandigital():
    pandigitals = set();
    for i in range(10, 99):
        for k in range(100, 999):
            product = i * k;
            if product >= 1000 and product <= 9999 and is_pandigital(i, k, product):
                pandigitals.add(product);
                print(i, ' * ', k, ' = ', product);
    for i in range(1000, 9999):
        for k in range(1, 9):
            product = i * k;
            if product >= 1000 and product <= 9999 and is_pandigital(i, k, product):
                pandigitals.add(product);
                print(i, ' * ', k, ' = ', product);

    print(sum(pandigitals));

test_number_of_pandigital();

