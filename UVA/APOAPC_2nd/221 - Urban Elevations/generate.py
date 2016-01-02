import random;

WIDTH = 1000;
DEPTH = 1000;

def get_x():
    global WIDTH;
    return random.uniform(0, WIDTH) + 0.5;

def get_y():
    global DEPTH;
    return random.uniform(0, DEPTH) + 0.5;

def get_width():
    global WIDTH ;
    return random.uniform(1, WIDTH/5);

def get_depth():
    global DEPTH;
    return random.uniform(1, DEPTH/5);

def get_height():
    return random.randint(2, 20);

n_building = 50;
print(n_building);

for i in range(n_building):
    print(get_x(), " ", get_y(), " ", get_width(), " ", get_depth(), " ", get_height());

print(0);
