def get_pentagon_list(size=10):
    pentagon_list = [1];
    d = 4;
    for i in range(1, size):
        pentagon_list.append(pentagon_list[-1] + d);
        d += 3;
    return pentagon_list;

# print(get_pentagon_list());

def test_pentagon_numbers():
    pentagon_list = get_pentagon_list(10000);
    pentagon_set = set(pentagon_list);
    for i in range(0, len(pentagon_list)):
        D = pentagon_list[i];
        for k in range(0, len(pentagon_list)):
            J = pentagon_list[k];
            if D+J in pentagon_set and D+J+J in pentagon_set:
                print(D);
                return;


test_pentagon_numbers();
