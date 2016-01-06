# for i in range(1, 100000):
#    print(i, 0);
import random;

num_command = 10;
to = 10;

if (to == 1):
    raise;

print(to, num_command);

def get_random_number():
    return random.randint(1, to);

def print_random_command():
    ch = random.choice([1, 2, 3, 4]);
    if ch == 4:
        print(4);
    else:
        x = get_random_number();
        y = get_random_number();
        while (y == x):
            y = get_random_number();
        print(ch, x, y);

for _ in range(num_command):
    print_random_command();
