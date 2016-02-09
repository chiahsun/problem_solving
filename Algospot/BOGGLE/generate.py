import random, string;

#random.seed(0);

#choice_space = string.ascii_uppercase;
choice_space = "ABCDEFGHIJK";

def generate_board():
    for _ in range(5):
        for _ in range(5):
            print(random.choice(choice_space), sep = '', end = '');
        print();

def generate_query():
    lenth = random.randint(1, 10);
    for _ in range(lenth):
        print(random.choice(choice_space), sep = '', end = '');
    print();


def generate_case(n_case = 1):
    print(n_case);
    for _ in range(n_case):
        generate_board();
        n_query = 10;
        print(n_query);
        for _ in range(n_query):
            generate_query();    

generate_case(20000);
