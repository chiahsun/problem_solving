# TODO: Can we not to use set?

def get_number_solution(bound = 1000):
    list_of_solution_set = [];
    for i in range(0, bound+1):
        list_of_solution_set.append(set());
#    list_of_solution_set = [set() for i in range(0, bound+1)];
    for k in range(1, bound//2+1):
        for m in range(1, int(bound/2/k)+2):
            n = 1;
            while (2 * k  * m * (m+n)) <= bound and m > n:
                z = k * (m**2 + n ** 2);
                x = k * 2 * m * n;
                y = k * (m**2 - n**2);
                res = x + y + z;
#                print(res, ' : ', x , ' ', y , ' ', z);
                ans = sorted((x, y, z));
                list_of_solution_set[res].add(tuple(ans));
                n += 1;
    for i in range(0, len(list_of_solution_set)):
        if len(list_of_solution_set[i]) != 0:
            print(i, ' : ', list_of_solution_set[i]);
    return (max(range(1, bound+1), key=lambda x: len(list_of_solution_set[x])));

print(get_number_solution());
