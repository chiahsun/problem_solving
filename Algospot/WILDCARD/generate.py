import random;

random.seed(0);
query_chars = ['a', 'b', 'c'];

def generate_wildcard(max_length=5):
    for i in range(random.randint(1, max_length)):
        print(random.choice(['*', '?'] + query_chars), end='', sep='');
    print();

def generate_query(max_length=100):
    for i in range(random.randint(1, max_length)):
        print(random.choice(query_chars), end='', sep='');
    print();



def generate_case(n_query=1):
    generate_wildcard();

    print(n_query);
    for _ in range(n_query):
        generate_query();

print(1);
generate_case(10000);
