def is_pandigital(lst):
    counts = [0] * 10;
    for i in lst:
        for c in str(i):
            counts[int(c)] += 1;
    return counts[0] == 0 and all(list(map(lambda x: x==1, counts[1:])));

def get_pandigital_multiples():
    for i in range(1000, 9999):
        if is_pandigital([i, i*2]):
            print(i , i * 2);

get_pandigital_multiples();

