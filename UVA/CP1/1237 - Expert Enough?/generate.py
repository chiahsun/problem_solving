import random;

n_case = 5;
print(n_case);

companys = ['HONDA', 'BMW', 'CHEVROLET', 'PEUGEOT', 'AUDI', 'FORD', 'MAZDA'];


upper_bound = 100;
lower_bound = 1;

def get_lower_and_upper_bound():
    global upper_bound;
    global lower_bound;
    up = random.randint(lower_bound, upper_bound);
    lo = random.randint(lower_bound, upper_bound);
    if (up == lo):
        if (up == upper_bound):
            lo = lo-1;
        else:
            up = up + 1;
    if (up < lo):
        up, lo = lo, up
    return (lo, up);
    
for _ in range(n_case):
    print(len(companys));
    for company in companys:
        (lo, up) = get_lower_and_upper_bound();
        print(company, lo, up);
    n_query = 100;
    print(n_query);
    for _ in range(n_query):
        print(random.randint(lower_bound, upper_bound));


