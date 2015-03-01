def get_next_number(number, step, type):
    return (number+step, step+type);

def get_next_tri_number(t):
    return get_next_number(t[0], t[1], 1);

def get_next_penta_number(t):
    return get_next_number(t[0], t[1], 3);

def get_next_hex_number(t):
    return get_next_number(t[0], t[1], 4);

def get_next_tri_penta_hex_number(t1, t2, t3):
    t1 = get_next_tri_number(t1);
    t2 = get_next_penta_number(t2);
    t3 = get_next_hex_number(t3);
    while t1[0] != t2[0] or t2[0] != t3[0] or t3[0] != t1[0]:
#    for i in range(1, 500):
#        print(t1, t2, t3);
        if t1[0]  == min(t1[0], t2[0], t3[0]):
            t1 = get_next_tri_number(t1);
        elif t2[0] == min(t2[0], t3[0]):
            t2 = get_next_penta_number(t2);
        else:
            t3 = get_next_hex_number(t3);
    return (t1, t2, t3);

# Reference
# http://stackoverflow.com/questions/2238355/what-is-the-pythonic-way-to-unpack-tuples
def test_get_tri_penta_hex_number():
    res1 = get_next_tri_penta_hex_number((1, 2), (1, 4), (1, 5))
    print(res1);
    res2 = get_next_tri_penta_hex_number(*res1);
    print(res2);

test_get_tri_penta_hex_number();
