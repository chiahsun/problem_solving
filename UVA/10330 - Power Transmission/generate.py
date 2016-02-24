import random;

def get_capacity():
    return random.randint(1, 1000);

def generate_edge(node_list):
    random.shuffle(node_list);
    ls = random.sample(node_list, 2);
    print(ls[0], ls[1], get_capacity());


def generate_case(n_node=random.randint(1, 100)):
    print(n_node);
    node_list = list(range(1, n_node+1));
    for i in range(n_node):
        print(get_capacity(), end=' ', sep='');
    print();
    n_edge = random.randint(0, (n_node*(n_node-1)/2));
    print(n_edge);
    for _ in range(n_edge):
        generate_edge(node_list);
    source_nodes = random.sample(node_list, random.randint(0, n_node));
    left_node_list = list(filter(lambda x : not x in source_nodes, node_list));
    sink_nodes = random.sample(left_node_list, random.randint(0, len(left_node_list)));
    print(len(source_nodes), len(sink_nodes));
    for x in source_nodes:
        print(x, end = ' ', sep = '');
    for x in sink_nodes:
        print(x, end = ' ', sep = '');
    print();

generate_case();
