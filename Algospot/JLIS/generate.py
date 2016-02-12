import random;

random.seed(0);

def generate_sequence(n_elem):
    for _ in range(n_elem):
        print(random.randint(1, 9), end=' ', sep='');
    print();

def generate_case(n1_bound=100, n2_bound=100):
    n1 = random.randint(1, n1_bound);
    n2 = random.randint(1, n2_bound);
    print(n1, n2);
    generate_sequence(n1);
    generate_sequence(n2);

def generate_all(n_case=100):
    print(n_case);
    for _ in range(n_case):
        generate_case(5, 5);
#        generate_case();

generate_all();
