import random;
random.seed(0);

def generate_case(length = random.randint(1, 100), n_var = random.randint(1, 10), valud_bound=1000):
    print(length, n_var);
    for _ in range(length):
        print(random.randint(1, valud_bound), sep='', end=' ');
    print();

def generate_all(n_case=50):
    print(n_case);
    for _ in range(n_case):
#        generate_case(5, 2, 10);
        generate_case();

#generate_all(10);
generate_all(1000);
