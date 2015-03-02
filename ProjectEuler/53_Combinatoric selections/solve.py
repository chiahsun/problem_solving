from math import factorial;

def get_number_selections_exceed_one_million():
    res = 0;
    for i in range(1, 100+1):
        for k in range(0, i+1):
            if factorial(i)/factorial(k)/factorial(i-k) > 10 ** 6:
                res += 1;
    print(res);

get_number_selections_exceed_one_million();
