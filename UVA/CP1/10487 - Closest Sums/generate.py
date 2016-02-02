import random;

def generate_case(n_int = 1000, n_query = 25):
    #INT_BOUND = 10000;
    #QUERY_BOUND = 1000;
    INT_BOUND = 10;
    QUERY_BOUND = 20;
    print(n_int);
    for _ in range(n_int):
        print(random.randint(-INT_BOUND, INT_BOUND));
    print(n_query);
    for _ in range(n_query):
        print(random.randint(-QUERY_BOUND, QUERY_BOUND));

for _ in range(100):
    generate_case(2);

print(0);
