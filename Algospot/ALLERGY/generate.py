import random;
random.seed();

friends=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'];
friends += ['v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'];
friends += ['O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'];

def generate_case(n_friend_bound=50, n_dish_bound=50):
    n_friend = random.randint(1, n_friend_bound);
    n_dish = random.randint(1, n_dish_bound);

    print(n_friend, n_dish);
    for i in range(n_friend):
        print(friends[i], end=' ', sep='');
    print();

    for _ in range(n_dish):
        customers = [];
        for _ in range(random.randint(1, int(n_friend/3+1))):
            customers += random.choice(friends[0:n_friend]);
        customers = list(set(customers));
        print(len(customers), end=' ', sep='');
        for cus in customers:
            print(cus,end=' ', sep='');
        print();

def generate_all(n_case=1):
    print(n_case);
    for i in range(n_case):
#        generate_case();
        generate_case(10, 10);

generate_all(1000);
