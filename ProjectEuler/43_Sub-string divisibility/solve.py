debug = False;

propert_set = set();

def get_all_permutation(lst):
    get_all_permutation_substructure(lst);

def is_divisable(lst, start, div):
    val = lst[start] * 100 + lst[start+1] * 10 + lst[start+2];
    return (val % div) == 0;

def is_property_list(lst):
    start_list = [1, 2, 3, 4, 5, 6, 7];
    div_list = [2, 3, 5, 7, 11, 13, 17];
    for i in range(0, len(start_list)):
        if not is_divisable(lst, start_list[i], div_list[i]):
            return False;
    return True;

def get_all_permutation_substructure(lst, cur_pos=0):
    global propert_set;
#    assert(lst != [1, 4, 0, 6, 3, 5, 7, 2, 8, 9]);
    start_list = [1, 2, 3, 4,  5,  6,  7];
    div_list =   [2, 3, 5, 7, 11, 13, 17];
    if is_property_list(lst):
        propert_set.add(int(''.join(map(str, lst))));
#        print(lst);
    if debug:
        for i in range(cur_pos):
            print('  ', end = '');
        print(lst);
    for i in range(cur_pos, len(lst)):
        lst[cur_pos], lst[i] = lst[i], lst[cur_pos];
        is_ok = all(map(lambda x: cur_pos <= start_list[x]+2 or is_divisable(lst, start_list[x], div_list[x]), range(0, len(start_list))));
        if is_ok: 
            get_all_permutation_substructure(lst, cur_pos+1);
        lst[cur_pos], lst[i] = lst[i], lst[cur_pos];

# print(is_property_list([1, 4, 0, 6, 3, 5, 7, 2, 8, 9]));
get_all_permutation(list(range(0, 10)));
print(sum(propert_set));
# get_all_permutation(list(range(0, 3)));
# get_all_permutation(list(range(0, 4)));
