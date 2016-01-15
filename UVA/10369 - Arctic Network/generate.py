import random;

print(1);
n_edge = 3;
n_node = 11;
print(n_edge, n_node);

for _ in range(n_node):
    print(random.randint(0, 100), random.randint(0, 100));
