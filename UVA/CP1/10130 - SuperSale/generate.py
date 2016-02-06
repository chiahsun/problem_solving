import random;
random.seed(0);

n_case = 1000;
print(n_case);

def print_object(price_bound = 100, weight_bound = 30):
    print(random.randint(1, price_bound), random.randint(1, weight_bound));

def print_people(weight_bound = 30):
    print(random.randint(1, weight_bound));

def print_case(n_object , n_people):
    print(n_object);
    for _ in range(n_object):
        print_object();
    print(n_people);
    for _ in range(n_people):
        print_people();

for _ in range(n_case):
    print_case(5, 5);
    # print_case(1000, 100);
