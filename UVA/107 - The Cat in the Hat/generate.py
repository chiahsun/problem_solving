import random;

for _ in range(10):
    height_max = 10000000;
    height, ncat = random.randint(2, height_max), 1;
    initial_height = height;
    while (height != 1):
        prev_height = height;
        for i in range(2, int(height+1)):
            if height % i == 0:
#                print(height, "/", i, ' = ', height / i);
                height /= i;
                ncat *= (i-1);
        if height == prev_height:
            raise;

    print(initial_height, ncat);

print(0, 0);
