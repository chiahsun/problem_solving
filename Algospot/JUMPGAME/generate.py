import random;


def generate_board():
    size = random.randint(2, 100);
    print(size);
    for _ in range(size):
        for _ in range(size):
            print(random.randint(1, 9), end=' ');
        print();
        
def generate_case(n_case=1):
    print(n_case);
    for _ in range(n_case):
        generate_board();

generate_case(50);
