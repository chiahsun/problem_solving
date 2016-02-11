import random;

def generate_string(num):
    for _ in range(num):
        print(random.choice(['M', 'F']), end='', sep='');
    print();

def generate_case(upper_bound=200000):
    n_member = random.randint(1, upper_bound);
    n_fan = random.randint(n_member, upper_bound);

    generate_string(n_member);
    generate_string(n_fan);

def call_generate_case(n_case=1):
    print(n_case);
    for _ in range(n_case):
        generate_case();

call_generate_case(20);
