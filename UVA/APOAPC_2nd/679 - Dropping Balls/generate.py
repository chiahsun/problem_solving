import random;

def get_random_balls():
    depth = random.randint(2, 20);
    nball = random.randint(1, 2 ** (depth-1));
    print(depth, nball);

ncase = 1000;

print(ncase);
for _ in range(ncase):
    get_random_balls();
print(-1);
