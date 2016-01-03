import random;

print(1);

n_jobs = 25;

def get_priority():
    return random.randint(1, 9);

print(n_jobs, random.randint(0, n_jobs-1));

for i in range(n_jobs):
    print(get_priority(), end = ' ');
print();
