import random;
import string;
random.seed(0);

def generate_seq(n_char = 100):
    for _ in range(n_char):
        print(random.choice(string.ascii_lowercase), end=' ');
    print('\n#');

generate_seq();
generate_seq();
