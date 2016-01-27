import random;
print(1);
print();
def get_matrix(nside):
    for _ in range(nside):
        for _ in range(nside):
            c = random.choice(['0', '1']);
            print(c, end='');
        print();

get_matrix(25);
