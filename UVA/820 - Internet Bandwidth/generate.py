import random;

def generate_case(max_num_node = 100):
    n_node = random.randint(2, max_num_node);
    all_nodes = list(range(1, n_node+1));
    src_and_dst = random.sample(all_nodes, 2);
    n_connection = random.randint(0, n_node * (n_node-1)/2);
    print(n_node);
    print(src_and_dst[0], src_and_dst[1], n_connection);

    for _ in range(n_connection):
        pr = random.sample(all_nodes, 2);
        print(pr[0], pr[1], random.randint(0, 1000));
    

generate_case(3000);
print(0);

